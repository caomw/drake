if(GTEST_FOUND)
  add_executable(value_test value_test.cc)
  target_link_libraries(value_test drakeSystemFramework ${GTEST_BOTH_LIBRARIES})
  add_test(NAME value_test COMMAND value_test)

  add_executable(named_value_vector_test named_value_vector_test.cc)
  target_link_libraries(named_value_vector_test drakeSystemFramework
    ${GTEST_BOTH_LIBRARIES})
  add_test(NAME named_value_vector_test COMMAND named_value_vector_test)

  add_executable(basic_vector_test basic_vector_test.cc)
  target_link_libraries(basic_vector_test drakeSystemFramework drakePolynomial
    drakeCore ${GTEST_BOTH_LIBRARIES})
  add_test(NAME basic_vector_test COMMAND basic_vector_test)
endif()
