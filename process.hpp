#pragma once
#include "./easy_mutex.hpp"
#include "./pollthread.hpp"
#include <vector>
#include <string>
#include <sstream>
#include <thread>

class process
{
private:
    static pollthread * poller;

    easy_mutex<std::string> from_process;
    int read_fd;
    int write_fd;
    int pid;

    process();
    process(const process &);
    process& operator=(const process &);
public:
    process(const std::vector<std::string> &cmd);
    int get_pid() const;
    bool is_runing() const;
    int exit_status() const;
    int waite() const;
    process& operator<<(const std::string &);
    process& operator>>(std::string &);
    ~process();
};
