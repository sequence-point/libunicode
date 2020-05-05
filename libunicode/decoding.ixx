namespace unicode {

inline std::uint32_t
utf8_decoder::extract(std::istream& i) const
{
  return decode(std::istreambuf_iterator< char >{ i },
                std::istreambuf_iterator< char >{});
}

} // namespace unicode
