#pragma once

// We could use a tuple but the accessors are not really meaningfull
class Rectangle
{
public:
    Rectangle() = default;
    Rectangle(unsigned o_left, unsigned o_top, unsigned o_right, unsigned o_bottom)
        : left(o_left), top(o_top), right(o_right), bottom(o_bottom)
    {}

    Rectangle(const Rectangle& other)
        : left(other.left), top(other.top), right(other.right), bottom(other.bottom)
                {}

    unsigned left, top, right, bottom;
};
