namespace unicode {

template< typename InputIterator >
std::uint32_t
utf8_decoder::decode(InputIterator& it, InputIterator const& end) const
{
  if (it == end)
    return replacement_character;

  std::uint32_t c1 = (unsigned char)*it++;

  // 1 byte (valid: 0 <= codepoint <= 0x7f)
  if (c1 <= 0x7f)
    return c1;

  if (it == end)
    return replacement_character;

  std::uint32_t c2 = (unsigned char)*it++;

  // 2 bytes (valid: 0x80 <= codepoint <= 0x7ff)
  if (c1 <= 0b11011111) {
    std::uint32_t c = ((c1 & 0b00011111) << 6) | (c2 & 0b00111111);

    if (c < 0x80) // overlong protection
      return replacement_character;

    return c;
  }

  if (it == end)
    return replacement_character;

  std::uint32_t c3 = (unsigned char)*it++;

  // 3 bytes (valid: 0x800 <= codepoint <= 0xffff)
  if (c1 <= 0b11101111) {
    std::uint32_t c =
      ((c1 & 0b00001111) << 12) | ((c2 & 0b00111111) << 6) | (c3 & 0b00111111);

    if (c < 0x800) // overlong protection
      return replacement_character;

    return c;
  }

  if (it == end)
    return replacement_character;

  std::uint32_t c4 = (unsigned char)*it++;

  // 4 bytes (valid: 0x10000 <= codepoint <= 0x10ffff)
  if (c1 <= 0b11110111) {
    std::uint32_t c = ((c1 & 0b00000111) << 18) | ((c2 & 0b00111111) << 12) |
                      ((c3 & 0b00111111) << 6) | (c4 & 0b00111111);

    if (c < 0x10000) // overlong protection
      return replacement_character;

    if (0x10ffff < c) // overflow protection
      return replacement_character;

    return c;
  }

  return replacement_character;
}

} // namespace unicode
