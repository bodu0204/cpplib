#pragma once
#include <mutex>

template <typename T>
class easy_mutex: public T, public std::mutex{};

#define MUTEX(__target__, __action__) __target__.lock();__action__;__target__.unlock();
