#pragma once

#include <string_view>

// Box drawing characters (https://symbl.cc/en/unicode-table/#box-drawing)
inline constexpr std::string_view BOX_H = "\u2500";  // ─  horizontal
inline constexpr std::string_view BOX_V = "\u2502";  // │  vertical
inline constexpr std::string_view BOX_TL = "\u250C"; // ┌  top-left
inline constexpr std::string_view BOX_TR = "\u2510"; // ┐  top-right
inline constexpr std::string_view BOX_BL = "\u2514"; // └  bottom-left
inline constexpr std::string_view BOX_BR = "\u2518"; // ┘  bottom-right
inline constexpr std::string_view BOX_LT = "\u251C"; // ├  left tee
inline constexpr std::string_view BOX_RT = "\u2524"; // ┤  right tee
inline constexpr std::string_view BOX_TT = "\u252C"; // ┬  top tee
inline constexpr std::string_view BOX_BT = "\u2534"; // ┴  bottom tee
inline constexpr std::string_view BOX_CR = "\u253C"; // ┼  cross
