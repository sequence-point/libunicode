#include <libunittest/unittest.hxx>

#include <libunicode/iterator.hxx>

DEFINE_TEST("UTF-8: input iterator")
{
  std::string utf8{ "hࠀ𐀀" };

  unicode::utf8_input_iterator< std::string::iterator > it{ utf8.begin(),
                                                            utf8.end() };

  std::uint32_t c1 = *it++;
  std::uint32_t c2 = *it++;
  std::uint32_t c3 = *it++;
  std::uint32_t c4 = *it++;

  TEST_EQUAL(it, utf8.end());

  TEST_EQUAL(c1, 'h');
  TEST_EQUAL(c2, 0x80);
  TEST_EQUAL(c3, 0x800);
  TEST_EQUAL(c4, 0x10000);
}
