#ifndef SRC_INTERFACE_COLOR_H_
#define SRC_INTERFACE_COLOR_H_
#include <map>
#include <string>

namespace study {

class Color {
 public:
  std::string Rize(std::string const& source,
                   std::string foreground_color = "Default",
                   std::string background_color = "Default",
                   std::string set_formatting = "Default",
                   std::string reset_formatting = "All") {
    std::string const control = "\033";
    if (color_foreground.find(foreground_color) == color_foreground.end())
      foreground_color = "Default";

    if (color_background.find(background_color) == color_background.end())
      background_color = "Default";

    if (formatting_set.find(set_formatting) == formatting_set.end())
      set_formatting = "Default";

    if (formatting_reset.find(reset_formatting) == formatting_reset.end())
      reset_formatting = "All";

    std::string ans = control + std::string{"["} +
                      formatting_set.at(set_formatting) + std::string{";"} +
                      color_background.at(background_color) + std::string{";"} +
                      color_foreground.at(foreground_color) + std::string{"m"} +
                      source + control + std::string{"["} +
                      formatting_reset.at(reset_formatting) + std::string{"m"};
    return ans;
  }

  const std::map<std::string, std::string> color_foreground = {
      {"Default", "39"},      {"Black", "30"},      {"Red", "31"},
      {"Green", "32"},        {"Yellow", "33"},     {"Blue", "34"},
      {"Magenta", "35"},      {"Cyan", "36"},       {"Light Gray", "37"},
      {"Dark Gray", "90"},    {"Light Red", "91"},  {"Light Green", "92"},
      {"Light Yellow", "93"}, {"Light Blue", "94"}, {"Light Magenta", "95"},
      {"Light Cyan", "96"},   {"White", "97"}};

  const std::map<std::string, std::string> color_background = {
      {"Default", "49"},       {"Black", "40"},       {"Red", "41"},
      {"Green", "42"},         {"Yellow", "43"},      {"Blue", "44"},
      {"Megenta", "45"},       {"Cyan", "46"},        {"Light Gray", "47"},
      {"Dark Gray", "100"},    {"Light Red", "101"},  {"Light Green", "102"},
      {"Light Yellow", "103"}, {"Light Blue", "104"}, {"Light Magenta", "105"},
      {"Light Cyan", "106"},   {"White", "107"}};

  const std::map<std::string, std::string> formatting_set = {
      {"Default", "0"}, {"Bold", "1"},    {"Dim", "2"},   {"Underlined", "4"},
      {"Blink", "5"},   {"Reverse", "7"}, {"Hidden", "8"}};

  const std::map<std::string, std::string> formatting_reset = {
      {"All", "0"},    {"Bold", "21"},    {"Dim", "22"},   {"Underlined", "24"},
      {"Blink", "25"}, {"Reverse", "27"}, {"Hidden", "28"}};
};

}  // namespace study

#endif  // SRC_INTERFACE_COLOR_H_
