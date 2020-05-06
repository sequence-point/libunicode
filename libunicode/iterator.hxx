#ifndef libunicode__iterator_hxx_
#define libunicode__iterator_hxx_

#include <libunicode/decoding.hxx>

#include <cstdint>

namespace unicode {

template< typename Decoder, typename IteratorType >
class unicode_input_iterator {
public:
  using decoder_type = Decoder;
  using iterator_type = IteratorType;
  using value_type = std::uint32_t;

  // TODO standard member types

  unicode_input_iterator()
  {}

  explicit unicode_input_iterator(iterator_type it) : it_{ std::move(it) }
  {
    decode();
  }

  unicode_input_iterator(iterator_type it, iterator_type end)
    : it_{ std::move(it) }, end_{ std::move(end) }
  {
    decode();
  }

  unicode_input_iterator(decoder_type decoder, iterator_type it)
    : decoder_{ std::move(decoder) }, it_{ std::move(it) }
  {
    decode();
  }

  unicode_input_iterator(decoder_type decoder,
                         iterator_type it,
                         iterator_type end)
    : decoder_{ std::move(decoder) },
      it_{ std::move(it) },
      end_{ std::move(end) }
  {
    decode();
  }

  value_type operator*() const
  {
    return unicode_;
  }

  unicode_input_iterator&
  operator++()
  {
    decode();
    return *this;
  }

  struct proxy {
    value_type unicode_;

    value_type operator*() const
    {
      return unicode_;
    }
  };

  proxy
  operator++(int)
  {
    auto unicode = unicode_;
    decode();
    return proxy{ unicode };
  }

  bool
  equal(iterator_type const& other) const
  {
    return it_ == other;
  }

private:
  void
  decode()
  {
    if (it_ != end_)
      unicode_ = decoder_.decode(it_, end_);
  }

  decoder_type decoder_;
  iterator_type it_;
  iterator_type end_;
  std::uint32_t unicode_{};
};

template< typename InputIterator >
using utf8_input_iterator =
  unicode_input_iterator< utf8_decoder, InputIterator >;

template< typename Decoder, typename IteratorType >
bool
operator==(
  unicode_input_iterator< Decoder, IteratorType > const& lhs,
  typename unicode_input_iterator< Decoder, IteratorType >::iterator_type const&
    rhs)
{
  return lhs.equal(rhs);
}

template< typename Decoder, typename IteratorType >
bool
operator!=(
  unicode_input_iterator< Decoder, IteratorType > const& lhs,
  typename unicode_input_iterator< Decoder, IteratorType >::iterator_type const&
    rhs)
{
  return !lhs.equal(rhs);
}

} // namespace unicode

#endif
