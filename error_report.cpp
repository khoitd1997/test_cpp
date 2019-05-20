static const auto kBold = "\033[1m";
static const auto kUnderline = "\033[4m";
static const auto kItalic = "\033[3m";
static const auto kFaint = "\033[2m";
static const auto kResetColorCode = "\033[0m";
static const auto kCyanColorCode = "\033[38;5;087m";
static const auto kGrey = "\033[38;5;246m";
static const auto kBlueColorCode = "\033[38;5;12m";
static const auto kYellowColorCode = "\033[38;5;226m";
static const auto kDarkYellowColorCode = "\033[38;5;220m";
static const auto kDarkGreenColorCode = "\033[38;5;34m";
static const auto kGreenColorCode = "\033[38;5;154m";

static const auto kTestColor = "\033[38;5;9m";
static const auto kTestColor2 = "\033[38;5;215m";

void testPrintMember(const std::string &memberName,
                     const std::string &formatting,
                     const std::string &correctType, const int lineNum,
                     const std::string &formattingType) {
  fmt::print("    + {}{}{} should be {}{}{} (line {})\n", formatting,
             memberName, kResetColorCode, formattingType, correctType,
             kResetColorCode, lineNum);
}

void testPrintTopFileName(const std::string &fileName) {
  fmt::print("\n{}{}{}:\n", kUnderline, fileName, kResetColorCode);
}

void testPrintIncludeFile(const std::string &includeFileName,
                          const std::string &parentFileName) {
  fmt::print("\n{}{}{} (included from {}):\n", kUnderline, includeFileName,
             kResetColorCode, parentFileName);
}

void testPrintTopFile(const std::string &fileName, const int total = 1) {
  //   testPrintTopFileName(fileName);
  testPrintIncludeFile(fileName, "fedora-main.toml");
  fmt::print("  {}distro_info:{}\n", kCyanColorCode, kResetColorCode);
  for (auto i = 0; i < total; ++i) {
    testPrintMember("partition_size", kTestColor, "int", i, kTestColor2);
  }
  //   fmt::print("  {}build_process:{}\n", kYellowColorCode, kResetColorCode);
  //   testPrintMember("cache", kGrey, "bool", 20);
}

void testVariant2(const std::string &fileName, const int lineNum,
                  const std::string &memberName,
                  const std::string &correctType) {
  fmt::print("\n{}{}:{}:{} {} should be {}{}{}", kBold, fileName, lineNum,
             kResetColorCode, memberName, kItalic, correctType,
             kResetColorCode);
}

void printSummary(const int totalError) {
  fmt::print("-----------------------------------------");
  fmt::print("\ntotal error(s): {}\n", totalError);
}

int main(void) {
  testPrintTopFile("fedora-kd.toml", 3);
  testPrintTopFile("fedora.toml");
  printSummary(5);

  //   fmt::print("\n");
  //   testVariant2("fedora-kd.toml", 12, "partition_size", "bool");
  //   testVariant2("fedora-kd.toml", 5, "package_cache", "int");

  //   fmt::print("\n");
  //   testVariant2("fedora.toml", 13, "delta_cache", "bool");
  //   testVariant2("fedora.toml", 1, "gamma_stuff", "string");
  return 0;
}