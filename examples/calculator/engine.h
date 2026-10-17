#pragma once

#include <string>

namespace calculator
{
    class Engine
    {
    public:
        const std::string& press(const std::string& key);

    private:
        std::string entry_{"0"};
        double accumulator_{0};
        std::string pending_operator_;
        bool replace_entry_{true};
    };
}
