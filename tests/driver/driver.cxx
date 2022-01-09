#include <sstream>
#include <stdexcept>

#include <re2/version.hxx>
#include <re2/re2.hxx>

#undef NDEBUG
#include <cassert>

int main ()
{
  using namespace std;
  using namespace re2;

  // Basics.
  //
  {
    ostringstream o;
    say_hello (o, "World");
    assert (o.str () == "Hello, World!\n");
  }

  // Empty name.
  //
  try
  {
    ostringstream o;
    say_hello (o, "");
    assert (false);
  }
  catch (const invalid_argument& e)
  {
    assert (e.what () == string ("empty name"));
  }
}
