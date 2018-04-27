#include "module.hh"
#include "internal/private.hh"

namespace is {

void println(std::string const& text) {
  print_mat();
  std::cout << text << std::endl;
}

}  // namespace is
