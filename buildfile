./: {*/ -build/ -tests/} doc{README} manifest

# Don't install tests.
#
tests/: install = false
