#ifndef UTILS_H
#define UTILS_H

namespace vm::utils
{
    template <typename T>
    T wrap(T value, T min, T max)
    {
        T range{ max - min };

        if (value < min || value > max)
        {
            value = value <  0 ? value + range : value - range;
        }
        return value;
    }
}

#endif
