#ifndef libunicode__encoding_hxx_
#define libunicode__encoding_hxx_

#include <ostream>

namespace unicode {

class encoder {
public:
  virtual ~encoder() = default;

  virtual void
  encode(std::ostream& o, std::uint32_t c) const = 0;
};

class utf8_encoder : public encoder {
public:
  void
  encode(std::ostream& o, std::uint32_t c) const override;
};

} // namespace unicode

#include <libunicode/encoding.ixx>

#endif
