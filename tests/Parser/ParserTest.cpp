#include <parserTest.hpp>

std::shared_ptr<cp::iparser::IParser> parser;

TEST_GROUP(ParseArgsTestGroup){
    void setup(){
        const std::vector<std::string> args = {"-v", "-d"};
std::unique_ptr<cp::iparser::IFactory> parserFactory = std::make_unique<cp::parser::PALFactory>();
parser = parserFactory->createParser(args);
}

void teardown()
{
    parser.reset();
}
}
;

TEST(ParseArgsTestGroup, VerboseFlag)
{
    int argc = 2;
    char *argv[] = {(char *)"program_name", (char *)"-v"};

    parser->args(argc, argv);

    CHECK_EQUAL(in_array("-v", parser->get()), true);
}

TEST(ParseArgsTestGroup, DebugFlag)
{
    int argc = 2;
    char *argv[] = {(char *)"program_name", (char *)"-d"};

    parser->args(argc, argv);
    CHECK_EQUAL(in_array("-d", parser->get()), true);
}

TEST(ParseArgsTestGroup, InvalidFlag)
{
    int argc = 2;
    char *argv[] = {(char *)"program_name", (char *)"-x"};

    CHECK_THROWS(std::runtime_error, parser->args(argc, argv));
}