#include "helpers.h"

using namespace cocoon;

namespace gallery
{
    View top_centered_page(const View& content, double top_inset)
    {
        View page;
        page.add_subview(content);
        LayoutConstraint::activate_constraints({
            content.center_x_anchor().constraint_equal_to_anchor(page.center_x_anchor()),
            content.top_anchor().constraint_equal_to_anchor(page.top_anchor(), top_inset),
        });
        return page;
    }
}
