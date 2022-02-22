set(LLVM_LINK_COMPONENTS
  Support
  )

add_llvm_tool(llls
  llls.cpp
)

get_target_property(CLAND_INCLUDE_DIRS clangDaemon INCLUDE_DIRECTORIES)

target_include_directories(llls
  PRIVATE
  ${CLAND_INCLUDE_DIRS}
)

target_link_libraries(llls
  PRIVATE
  clangDaemon
)
