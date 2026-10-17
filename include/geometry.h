#pragma once

namespace cocoon
{
    /**
     * @brief A 2D point (mirrors CGPoint). @par Example
     * @code
     * cocoon::Point origin{10, 20};
     * @endcode
     */
    struct Point
    {
        double x = 0;
        double y = 0;
    };

    /**
     * @brief A width and height (mirrors CGSize). @par Example
     * @code
     * cocoon::Size size{640, 480};
     * @endcode
     */
    struct Size
    {
        double width = 0;
        double height = 0;
    };

    /**
     * @brief A rectangle made of an origin and size (mirrors CGRect). @par Example
     * @code
     * cocoon::Rect frame{{0, 0}, {640, 480}};
     * @endcode
     */
    struct Rect
    {
        Point origin;
        Size size;
    };

    /**
     * @brief Edge insets (mirrors NSEdgeInsets). @par Example
     * @code
     * cocoon::Insets uniform(8);
     * cocoon::Insets symmetric(8, 16);       // vertical, horizontal
     * cocoon::Insets each(1, 2, 3, 4);       // top, left, bottom, right
     * @endcode
     */
    struct Insets
    {
        double top = 0;
        double left = 0;
        double bottom = 0;
        double right = 0;

        /// Zero insets.
        Insets() = default;
        /// The same inset on every edge.
        Insets(double all) : top(all), left(all), bottom(all), right(all)
        {
        }
        /// Vertical (top and bottom) and horizontal (left and right) insets.
        Insets(double vertical, double horizontal) : top(vertical), left(horizontal), bottom(vertical), right(horizontal)
        {
        }
        /// Individual insets for each edge.
        Insets(double top, double left, double bottom, double right) : top(top), left(left), bottom(bottom), right(right)
        {
        }
    };
}
