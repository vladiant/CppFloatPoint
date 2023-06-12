// Based on https://pvs-studio.com/en/blog/posts/cpp/0074/

int main() {
  float fConst = 1.4318620f;
  float fValue1 = 40.598053f * (1.f - 1.4318620f / 100.f);
  float fValue2 = 40.598053f * (1.f - fConst / 100.f);

  return (fValue1 == fValue2);
}