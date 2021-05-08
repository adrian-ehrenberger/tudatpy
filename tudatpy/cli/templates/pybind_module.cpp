/*    Copyright (c) {{ copyright_dates }}, {{ institution }}
 *    All rights reserved
 *
 *    This file was autogenerated by {{ tool_name }}. It is intended to serve
 *    as an example component a support header for a {{ project_type }} type
 *    {{ organisation }} project. Redistribution and use in source and
 *    binary forms, with or without modification, are permitted exclusively
 *    under the terms of the Modified BSD license. You should have received
 *    a copy of the license with this file. If not, please or visit:
 *    {{ url_license }}.
 */

{% for submodule in kernel_submodules -%}
    #include "expose_{{ submodule }}.h"
{% endfor %}
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(kernel, m) {

  // Disable automatic function signatures in the docs.
  // NOTE: the 'options' object needs to stay alive
  // throughout the whole definition of the module.
  py::options options;
  options.disable_function_signatures();
  options.enable_user_defined_docstrings();

  {% for submodule in kernel_submodules -%}
  // {{ submodule }} module
  auto {{ submodule }} = m.def_submodule("{{ submodule }}");
  {{ project_name }}::expose_{{ submodule }}({{ submodule }});

  {% endfor %}
#ifdef VERSION_INFO
  m.attr("__version__") = VERSION_INFO;
#else
  m.attr("__version__") = "dev";
#endif
}
