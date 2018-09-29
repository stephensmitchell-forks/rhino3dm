#include "bindings.h"

#pragma once

class BND_Object
{
  BND_Object(ON_Object* obj);
protected:
  std::shared_ptr<ON_Object> m_object;
  BND_Object();
public:
  virtual ~BND_Object();

#if defined(__EMSCRIPTEN__)
  emscripten::val Encode() const;
  static BND_Object* Decode(emscripten::val jsonObject);
#endif

#if defined(ON_PYTHON_COMPILE)
  boost::python::dict Encode() const;
  static BND_Object* Decode(boost::python::dict jsonObject);
#endif
};