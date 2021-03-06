/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Terminal/blob/master/LICENSE.txt
*/

#include "TerminalOutputTests.h"
#include "Ishiko/Terminal/TerminalOutput.h"
#include <Ishiko/Process/CurrentProcess.h>
#include <boost/filesystem/operations.hpp>

using namespace Ishiko::Terminal;
using namespace Ishiko::Tests;

TerminalOutputTests::TerminalOutputTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "TerminalOutput tests", environment)
{
    append<HeapAllocationErrorsTest>("Construction test 1", ConstructionTest1);
    append<FileComparisonTest>("write test 1", WriteTest1);
    append<FileComparisonTest>("write test 2", WriteTest2);
    append<FileComparisonTest>("write test 3", WriteTest3);
    append<FileComparisonTest>("write test 4", WriteTest4);
}

void TerminalOutputTests::ConstructionTest1(Test& test)
{
    TerminalOutput output(stdout);

    ISHTF_PASS();
}

void TerminalOutputTests::WriteTest1(FileComparisonTest& test)
{
    boost::filesystem::path outputPath(test.environment().getTestOutputDirectory() / "TerminalOutputTests_WriteTest1.txt");
    boost::filesystem::remove(outputPath);
    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.environment().getReferenceDataDirectory() / "TerminalOutputTests_WriteTest1.txt");

    Ishiko::Process::CurrentProcess::RedirectStandardOutputToFile(outputPath.string());

    TerminalOutput output(stdout);
    output.write("text");

    Ishiko::Process::CurrentProcess::RedirectStandardOutputToTerminal();

    ISHTF_PASS();
}

void TerminalOutputTests::WriteTest2(FileComparisonTest& test)
{
    boost::filesystem::path outputPath(test.environment().getTestOutputDirectory() / "TerminalOutputTests_WriteTest2.txt");
    boost::filesystem::remove(outputPath);
    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.environment().getReferenceDataDirectory() / "TerminalOutputTests_WriteTest2.txt");

    Ishiko::Process::CurrentProcess::RedirectStandardOutputToFile(outputPath.string());

    TerminalOutput output(stdout);
    std::string text = "text";
    output.write(text);

    Ishiko::Process::CurrentProcess::RedirectStandardOutputToTerminal();

    ISHTF_PASS();
}

void TerminalOutputTests::WriteTest3(FileComparisonTest& test)
{
    boost::filesystem::path outputPath(test.environment().getTestOutputDirectory() / "TerminalOutputTests_WriteTest3.txt");
    boost::filesystem::remove(outputPath);
    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.environment().getReferenceDataDirectory() / "TerminalOutputTests_WriteTest3.txt");

    Ishiko::Process::CurrentProcess::RedirectStandardOutputToFile(outputPath.string());

    TerminalOutput output(stdout);
    output.write("text", Ishiko::Color::eRed);

    Ishiko::Process::CurrentProcess::RedirectStandardOutputToTerminal();

    ISHTF_PASS();
}

void TerminalOutputTests::WriteTest4(FileComparisonTest& test)
{
    boost::filesystem::path outputPath(test.environment().getTestOutputDirectory() / "TerminalOutputTests_WriteTest4.txt");
    boost::filesystem::remove(outputPath);
    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.environment().getReferenceDataDirectory() / "TerminalOutputTests_WriteTest4.txt");

    Ishiko::Process::CurrentProcess::RedirectStandardOutputToFile(outputPath.string());

    TerminalOutput output(stdout);
    std::string text = "text";
    output.write(text, Ishiko::Color::eRed);

    Ishiko::Process::CurrentProcess::RedirectStandardOutputToTerminal();

    ISHTF_PASS();
}
