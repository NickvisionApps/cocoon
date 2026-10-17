#include <cmath>
#include <cstdio>
#include "engine.h"

namespace calculator
{
    const std::string& Engine::press(const std::string& key)
    {
        if (key.size() == 1 && key[0] >= '0' && key[0] <= '9')
        {
            entry_ = replace_entry_ || entry_ == "0" ? key : entry_ + key;
            replace_entry_ = false;
        }
        else if (key == ".")
        {
            if (replace_entry_)
            {
                entry_ = "0";
            }
            if (entry_.find('.') == std::string::npos)
            {
                entry_ += '.';
            }
            replace_entry_ = false;
        }
        else if (key == "AC")
        {
            entry_ = "0";
            accumulator_ = 0;
            pending_operator_.clear();
            replace_entry_ = true;
        }
        else if (key == "back")
        {
            if (!replace_entry_)
            {
                entry_.pop_back();
                if (entry_.empty() || entry_ == "-")
                {
                    entry_ = "0";
                }
            }
        }
        else if (key == "neg")
        {
            if (entry_ != "0")
            {
                entry_ = entry_[0] == '-' ? entry_.substr(1) : "-" + entry_;
            }
        }
        else if (key == "pct")
        {
            entry_ = std::to_string(std::stod(entry_) / 100);
            replace_entry_ = true;
        }
        else
        {
            double value = std::stod(entry_);
            if (!pending_operator_.empty() && !replace_entry_)
            {
                if (pending_operator_ == "+")
                {
                    accumulator_ += value;
                }
                else if (pending_operator_ == "-")
                {
                    accumulator_ -= value;
                }
                else if (pending_operator_ == "*")
                {
                    accumulator_ *= value;
                }
                else
                {
                    accumulator_ /= value;
                }
            }
            else if (pending_operator_.empty())
            {
                accumulator_ = value;
            }

            char buffer[32];
            std::snprintf(buffer, sizeof(buffer), "%.10g", accumulator_);
            entry_ = std::isfinite(accumulator_) ? buffer : "Error";
            pending_operator_ = key == "=" ? "" : key;
            replace_entry_ = true;
        }
        return entry_;
    }
}
