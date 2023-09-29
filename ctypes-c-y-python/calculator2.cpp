#define DLLEXPORT extern "C" __declspec(dllexport)

DLLEXPORT float add(float a, float b)
{
  return a + b;
}

DLLEXPORT float subtract(float a, float b)
{
  return a - b;
}

DLLEXPORT float multiply(float a, float b)
{
  return a * b;
}

DLLEXPORT float divide(float a, float b)
{
  if (b != 0)
  {
    return a / b;
  }
  else
  {

    return 0.0;
  }
}