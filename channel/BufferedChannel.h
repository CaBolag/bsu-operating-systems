#ifndef CHANNEL__BUFFEREDCHANNEL_H_
#define CHANNEL__BUFFEREDCHANNEL_H_

#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>


template<class T>
class BufferedChannel {

 public:
  explicit BufferedChannel(int size);
  BufferedChannel& operator =(BufferedChannel&& other);

  void Send(T value);
  std::pair<T, bool> Recv();
  void Close();

 private:
  std::queue<T> values_;
  std::condition_variable input_output_cv_;
  std::mutex mutex_;
  int buffer_size_;
  bool is_open_;
};


template <class T>
BufferedChannel<T>::BufferedChannel(int size):buffer_size_(size),is_open_(true) {}

template <class T>
void BufferedChannel<T>::Send(T value)
{
  if (!is_open_) {
    throw std::runtime_error("Channel is closed!");
  }
  std::unique_lock<std::mutex> locker(mutex_);

  input_output_cv_.wait(locker, [this] {return buffer_size_>values_.size(); });
  values_.push(value);
  locker.unlock();
  input_output_cv_.notify_one();
}

template <class T>
std::pair<T, bool> BufferedChannel<T>::Recv()
{
  std::unique_lock<std::mutex> locker(mutex_);

  if (values_.empty())
  {
    input_output_cv_.wait(locker, [this]() { return !values_.empty() || !is_open_; });
    if (values_.empty() && !is_open_)
    {
      return std::pair<T, bool>(T(), false);
    }
  }

  T recieved_value = values_.front();
  values_.pop();
  locker.unlock();
  input_output_cv_.notify_one();
  return std::pair<T, bool>(recieved_value , is_open_);
}

template<class T>
void BufferedChannel<T>::Close()
{
  is_open_ = false;
  input_output_cv_.notify_all();
}

#endif //CHANNEL__BUFFEREDCHANNEL_H_
