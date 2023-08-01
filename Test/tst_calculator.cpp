#include <QtTest>


#include "../Calculator/calculator.h"
#include "../Calculator/mylineedit.h"


class CalculatorTest : public QObject
{
    Q_OBJECT

public:
    CalculatorTest(){}
    ~CalculatorTest(){}

private slots:
    void test_Sum();
    void test_Diff();
    void test_Mult();
    void test_Div();



    void testGui();

    private:


    MyLineEdit line;

};



void CalculatorTest::test_Sum()
{
        Calculator calc(2,3);
        QCOMPARE(calc.Sum(), 5);
}

void CalculatorTest::test_Diff()
{
        Calculator calc(6,3);
        QCOMPARE(calc.Diff(), 3);
}

void CalculatorTest::test_Mult()
{
        Calculator calc(2,3);
        QCOMPARE(calc.Mult(), 6);
}

void CalculatorTest::test_Div()
{
        Calculator calc(10,5);
        QCOMPARE(calc.Div(), 2);
}




void CalculatorTest::testGui()
{

        QTest::keyClicks(&line, "ABCDEFGH");

        QCOMPARE(line.text(), QString("ABCDEFGH"));
        QVERIFY(line.isModified());
}


QTEST_MAIN(CalculatorTest)

#include "tst_calculator.moc"
