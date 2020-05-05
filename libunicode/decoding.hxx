#ifndef libunicode__decoding_hxx_
#define libunicode__decoding_hxx_

#include <libunicode/unicode.hxx>

#include <cstdint>

namespace unicode {

class utf8_decoder {
public:
  template< typename InputIterator >
  std::uint32_t
  decode(InputIterator& it, InputIterator const& end) const;

  template< typename InputIterator >
  std::uint32_t
  decode(InputIterator&& it, InputIterator const& end) const
  {
    return decode(it, end);
  }
};

} // namespace unicode

#include <libunicode/decoding.txx>

#endif
