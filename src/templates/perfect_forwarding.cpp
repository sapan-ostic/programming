/**
 * @file perfect_forwarding.cpp
 * @author Sapan Agrawal (ssagrawal@wpi.edu)
 * @date 2022-03-29
 * @copyright Copyright (c) 2022
 * @brief We want to preserve the type of argument when invoking the base class.
 * Thus, if l-value is passed, we want to call the copy constructor and if
 * r-value is passed, we want to call the move constructor. For non-templated
 * class, we would need to create 2^n constructors for n arguments which would
 * alot of work. This could be instead done using a single constructor using
 * std::forwarding<>. Tempates allow to pass both l & r values to the
 * constructor.
 */

#include "perfect_forwarding.h"
#include "util.h"

int main() {
  std::string name{"John"};

  // Copy-Copy, Both l-value
  case(1);
  { Base obj{10}; Entity entity1{name, obj}; }
  { Base obj{10}; TemplatedEntity t_entity1{name, obj}; }

  // Copy-Move, name (l-value) obj (r-value)
  case(2);
  { Entity entity1(name, Base{10}); }
  { TemplatedEntity t_entity1{name, Base{10}}; }

  // Move-Copy, name (r-value) obj (l-value)
  case(3);
  { Base obj{10}; Entity entity1{"John", obj}; }
  { Base obj{10}; TemplatedEntity t_entity1{"John", obj}; }

  // Move-Move, name (r-value) obj (r-value)
  case(4);
  { Entity entity1{"John", Base{10}}; }
  { TemplatedEntity t_entity1{"John", Base{10}}; }
  return 0;
}
