namespace gomoku {
  class stone
  {
    private:
      int color_value_; // 0: empty, 1: white, 2: black
      bool validate(int color_value);
      
    public:
      stone(int color_value);
      virtual ~stone();
      int get() const noexcept;
      void set(int color_value);
  };
} // namespace gomoku

gomoku::stone::stone(int color_value)
{
  if (!this->validate(color_value)) 
  this->color_value_ = color_value;
}

bool gomoku::stone::validate(int color_value)
{
  if (color_value == 1 || color_value == 2 || color_value == 0) return true;
  return false;
}
