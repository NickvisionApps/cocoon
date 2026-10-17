#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "engine.h"
#include "main_window.h"

using namespace cocoon;

namespace calculator
{
    MainWindow::MainWindow()
        : Window{
              "Calculator",
              {288, 420},
              WindowStyle::Titled | WindowStyle::Closable | WindowStyle::Miniaturizable | WindowStyle::Resizable |
                  WindowStyle::FullSizeContentView}
    {
        set_titlebar_appears_transparent(true);
        set_content_min_size({240, 360});
        auto engine = std::make_shared<Engine>();

        Label display{"0"};
        display.set_font(Font::monospaced_digit_system_font_of_size(44, 0.2));
        display.set_alignment(TextAlignment::Right);
        display.set_content_hugging_priority(1, ConstraintOrientation::Vertical);

        VStack grid;
        grid.set_spacing(8);
        grid.set_content_hugging_priority(999, ConstraintOrientation::Vertical);

        const std::vector<std::vector<std::pair<std::string, std::string>>> rows{
            {{"\xE2\x8C\xAB", "back"}, {"AC", "AC"}, {"%", "pct"}, {"\xC3\xB7", "/"}},
            {{"7", "7"}, {"8", "8"}, {"9", "9"}, {"\xC3\x97", "*"}},
            {{"4", "4"}, {"5", "5"}, {"6", "6"}, {"\xE2\x88\x92", "-"}},
            {{"1", "1"}, {"2", "2"}, {"3", "3"}, {"+", "+"}},
            {{"\xC2\xB1", "neg"}, {"0", "0"}, {".", "."}, {"=", "="}},
        };
        for (const auto& row : rows)
        {
            HStack line;
            line.set_spacing(8);
            line.set_distribution(StackViewDistribution::FillEqually);
            for (const auto& [title, key] : row)
            {
                Button button{title};
                button.set_bezel_style(BezelStyle::Glass);
                button.set_border_shape(ControlBorderShape::Circle);
                if (key == "/" || key == "*" || key == "-" || key == "+" || key == "=")
                {
                    button.set_bezel_color(Color::system_orange_color());
                }
                else if (key == "back" || key == "AC" || key == "pct")
                {
                    button.set_bezel_color(Color::system_gray_color());
                }
                else
                {
                    button.set_bezel_color(Color::dark_gray_color());
                }
                LayoutConstraint::activate_constraints(
                    {button.height_anchor().constraint_equal_to_anchor(button.width_anchor(), 1)});
                button.clicked().connect([engine, display, key]
                {
                    display.set_string_value(engine->press(key));
                });
                line.add_arranged_subview(button);
            }
            grid.add_arranged_subview(line);
            LayoutConstraint::activate_constraints({
                line.leading_anchor().constraint_equal_to_anchor(grid.leading_anchor()),
                line.trailing_anchor().constraint_equal_to_anchor(grid.trailing_anchor()),
            });
        }

        VStack content;
        content.set_spacing(8);
        content.set_alignment(LayoutAttribute::Width);
        content.add_arranged_subview(display);
        content.add_arranged_subview(grid);
        LayoutConstraint::activate_constraints({
            grid.leading_anchor().constraint_equal_to_anchor(content.leading_anchor()),
            grid.trailing_anchor().constraint_equal_to_anchor(content.trailing_anchor()),
        });
        View page;
        page.add_subview(content);
        content.pin_to_safe_area(Insets{16});
        set_content(page);

        Toolbar toolbar{"com.cocoon.calculator.toolbar"};
        toolbar.set_allows_user_customization(false);
        toolbar.set_autosaves_configuration(false);
        set_toolbar(toolbar);
        set_toolbar_style(ToolbarStyle::Unified);
    }
}
