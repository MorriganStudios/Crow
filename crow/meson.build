libcrow_inc = include_directories('include')

libcrow = shared_library(
  'crow',
  sources : [
    'src/window_glfw.c',
  ],
  include_directories : libcrow_inc,
  dependencies : [
    dependency('glfw3', required : true),
    dependency('GL', required : true),
  ],
  install : false,
)

libcrow_dep = declare_dependency(
  include_directories : libcrow_inc,
  link_with : libcrow
)
