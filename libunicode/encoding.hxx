#ifndef libunicode__encoding_hxx_
#define libunicode__encoding_hxx_

#include <ostream>

namespace unicode {

class utf8_encoder {
public:
  void
  encode(std::ostream& o, std::uint32_t c) const;
};

} // namespace unicode

#include <libunicode/encoding.ixx>

#endif
