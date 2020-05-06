namespace unicode {

template< typename Decoder, typename IteratorType >
unicode_input_iterator< Decoder, InputIterator >::unicode_input_iterator(
  iterator_type&& it,
  iterator_type&& end)
{}

template< typename Decoder, typename IteratorType >
unicode_input_iterator< Decoder, IteratorType >::value_type
  unicode_input_iterator< Decoder, IteratorType >::operator*() const
{}

bool
unicode_input_iterator< Decoder, IteratorType >::equal(
  unicode_input_iterator const& other) const
{
  return is_eof() == other.is_eof();
}

} // namespace unicode
