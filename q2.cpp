#include <queue>
#include <mutex>
#include <condition_variable>
#include <memory>

template <typename T>
class SyncQueue {
public:
    // Pops an element from the queue. It blocks if the queue is empty.
    T pop() {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this] { return !queue_.empty(); });
        T item = queue_.front();
        queue_.pop();
        return item;
    }

    // Pushes an element into the queue
    void push(const T& item) {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(item);
        cv_.notify_one();
    }

    SyncQueue() {}

    // Move constructor
    SyncQueue(SyncQueue&& other) noexcept {
        std::lock_guard<std::mutex> lock_this(mutex_);
        std::lock_guard<std::mutex> lock_other(other.mutex_);
        queue_ = std::move(other.queue_);
    }

    // Move assignment operator
    SyncQueue& operator=(SyncQueue&& other) noexcept {
        if (this != &other) {
            std::lock(mutex_, other.mutex_);
            std::lock_guard<std::mutex> lock_this(mutex_, std::adopt_lock);
            std::lock_guard<std::mutex> lock_other(other.mutex_, std::adopt_lock);
            queue_ = std::move(other.queue_);
        }
        return *this;
    }

private:
    std::queue<T> queue_;
    mutable std::mutex mutex_;
    std::condition_variable cv_;
};

int main() {
    SyncQueue<int> q1;
    SyncQueue<int> q2 = std::move(q1);
    return 0;
}