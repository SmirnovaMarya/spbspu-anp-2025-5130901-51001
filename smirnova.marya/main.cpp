#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
namespace smirnova
{
  int identical_str(const char *a, const char *b, size_t n, size_t m)
  {
    for (size_t i = 0; i < n; i++)
    {
      for (size_t j = 0; j < m; j++)
      {
        if (a[i] == b[j])
        {
          return 1;
        }
      }
    }
    return 0;
  }
  char *concatenation_str(const char *a, const char *b, size_t n, size_t m)
  {
    size_t length = n + m + 1;
    char *result = static_cast<char *>(std::malloc(length));
    if (!result)
    {
      return nullptr;
    }
    size_t count = 0;
    for (size_t i = 0; i < n; i++)
    {
      result[count++] = a[i];
    }
    for (size_t i = 0; i < m; i++)
    {
      if (std::isdigit(b[i]))
      {
        for (size_t j = 0; j < n; j++)
        {
          if (a[j] == b[i])
          {
            result[count++] = b[i];
            break;
          }
        }
      }
    }
    result[count] = '\0';
    return result;
  }
}
int main()
{
  std::string l1, l2;
  if (!std::getline(std::cin, l1))
  {
    std::cerr << "Couldn't read the first line\n";
    return 1;
  }
  if (!std::getline(std::cin, l2))
  {
    l2 = "Hello, 1 user from 1 terminal\n";
  }
  size_t n = l1.length();
  size_t m = l2.length();
  int a = smirnova::identical_str(l1.c_str(), l2.c_str(), n, m);
  std::cout << a << "\n";
  char *result2 = smirnova::concatenation_str(l1.c_str(), l2.c_str(), n, m);
  if (!result2)
  {
    std::cerr << "Memory allocation error\n";
    return 1;
  }
  std::cout << result2 << "\n";
  std::free(result2);
  return 0;
}
