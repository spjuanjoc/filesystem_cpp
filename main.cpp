#include <chrono>
#include <filesystem>
#include <iostream>
// namespace fs = std::experimental::filesystem;
namespace fs = std::filesystem;

int main() {
  std::cout << "Hola std::filesystem\n";

  try {
    auto cwd = fs::current_path();
    std::cout << "fs::cwd= " << cwd << '\n';
    fs::path p("../../test.txt");

    auto ftime = fs::last_write_time(p);
    auto cftime =
        std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::cout << "fs::last_write_time= " << cftime << '\n';
    //    fs::last_write_time(p, cftime);
  } catch (const std::exception &ex) {
    std::cout << ex.what();
  }

  return 0;
}
