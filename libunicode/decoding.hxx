#ifndef libunicode__decoding_hxx_
#define libunicode__decoding_hxx_

#include <libunicode/unicode.hxx>

#include <cstdint>
#include <istream>
#include <iterator>

namespace unicode {

class decoder {
public:
  virtual ~decoder() = default;

  virtual std::uint32_t
  extract(std::istream& i) const = 0;
};

class utf8_decoder : public decoder {
public:
  std::uint32_t
  extract(std::istream& i) const override;

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

#include <libunicode/decoding.ixx>
#include <libunicode/decoding.txx>

#endif
