class FixedPointTheorem {
 public:
  double cycleRange(double R);
  double f(double X);
  double R;
};

double FixedPointTheorem::cycleRange(double R) {
  (*this).R = R;
  double FX = 0.25;
  for (int i = 0; i < 200000; ++i) {
    FX = f(FX);
  }
  double low = f(FX), high = low;
  for (int i = 0; i < 1000; i++) {
    FX = f(FX);
    low = (low < FX) ? low : FX;
    high = (high > FX) ? high : FX;
  }
  return high - low;
}

double FixedPointTheorem::f(double X) {
  return R * X * (1 - X);
}
