namespace unicode {

inline void
utf8_encoder::encode(std::ostream& o, std::uint32_t c) const
{
  // 1 byte
  if (c <= 0x7f) {
    o.put(c);
    return;
  }

  // 2 bytes
  if (c <= 0x7FF) {
    o.put(0b11000000 | ((c >> 6) & 0b00011111));
    o.put(0b10000000 | (c & 0b00111111));
    return;
  }

  // 3 bytes
  if (c <= 0xFFFF) {
    o.put(0b11100000 | ((c >> 12) & 0b00001111));
    o.put(0b10000000 | ((c >> 6) & 0b00111111));
    o.put(0b10000000 | (c & 0b00111111));
    return;
  }

  // 4 bytes
  if (c <= 0x10FFFF) {
    o.put(0b11110000 | ((c >> 18) & 0b00000111));
    o.put(0b10000000 | ((c >> 12) & 0b00111111));
    o.put(0b10000000 | ((c >> 6) & 0b00111111));
    o.put(0b10000000 | (c & 0b00111111));
    return;
  }
}

} // namespace unicode
