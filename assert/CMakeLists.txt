ADD_EXECUTABLE ( assert_test  assert_test.c )
ADD_LIBRARY ( my_assert STATIC assert.c )
TARGET_LINK_LIBRARIES ( assert_test PUBLIC my_assert )
