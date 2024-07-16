#include <stdexcept>

class NotImplementedException : std::logic_error {
public:
  NotImplementedException()
      : NotImplementedException("Not implemented yet: ") {}

  NotImplementedException(const char *message)
      : NotImplementedException(message, __FUNCTION__) {}

  virtual const char *what() const throw() { return this->text.c_str(); }

private:
  std::string text;

  NotImplementedException(const char *message, const char *function)
      : std::logic_error("Not implemented yet") {
    this->text = message;
    this->text += " : ";
    this->text += function;
  }
};
