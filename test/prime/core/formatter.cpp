#include "../../testframe.hxx"
#include "../../../native/core/formatter.hpp"

class TestClass : public tianyu::IToString
{
    __PUB__ ~TestClass() __override_func { }

    __PUB__::string ToString() noexcept __override_func
    {
        ::string result = new char[10];
        result[0] = 'T';
        result[1] = 'e';
        result[2] = 's';
        result[3] = 't';
        result[4] = 'C';
        result[5] = 'l';
        result[6] = 'a';
        result[7] = 's';
        result[8] = 's';
        result[9] = '\0';

        return result;
    }
};

class TestClassNoToString { };

TEST_MAIN("tianyu.common.native.test.prime.core.formatter")
{
    entity.StartSpec("format", [](tianyu::test::TestEntity& entity) -> void
        {
            // format calls tianyu-core format functions that is tested in tianyu.common.native.test.tianyu-core.value_to_string
            // to simple check here

            entity.RunTest("char", "format - empty & integer", [](tianyu::test::TestObject& tobj) -> void
                {
                    ::string empty = tianyu::FormatHelper::Format('a', (::string)"");
                    ::string intf = tianyu::FormatHelper::Format('a', (::string)"d");

                    if (tobj.IsNotNull(empty))
                    {
                        tobj.EQ(empty, (::string)"a");
                        delete [] empty;
                    }
                    if (tobj.IsNotNull(intf))
                    {
                        tobj.EQ(intf, (::string)"97");
                        delete [] intf;
                    }
                });
            entity.RunTest("uchar", "format - empty & integer", [](tianyu::test::TestObject& tobj) -> void
                {
                    ::string empty = tianyu::FormatHelper::Format((uchar)'a', (::string)"");
                    ::string intf = tianyu::FormatHelper::Format((uchar)'a', (::string)"d");

                    if (tobj.IsNotNull(empty))
                    {
                        tobj.EQ(empty, (::string)"a");
                        delete [] empty;
                    }
                    if (tobj.IsNotNull(intf))
                    {
                        tobj.EQ(intf, (::string)"97");
                        delete [] intf;
                    }
                });
            entity.RunTest("int16", "format - empty & bin & oct & dec & hex", [](tianyu::test::TestObject& tobj) -> void
                {
                    ::string empty = tianyu::FormatHelper::Format((int16)123, (::string)"");
                    ::string bin = tianyu::FormatHelper::Format((int16)123, (::string)"B");
                    ::string oct = tianyu::FormatHelper::Format((int16)123, (::string)"O");
                    ::string dec = tianyu::FormatHelper::Format((int16)123, (::string)"d");
                    ::string hex = tianyu::FormatHelper::Format((int16)123, (::string)"X");
                    ::string ndec = tianyu::FormatHelper::Format((int16)-123, (::string)"d");

                    if (tobj.IsNotNull(empty))
                    {
                        tobj.EQ(empty, (::string)"123");
                        delete [] empty;
                    }
                    if (tobj.IsNotNull(bin))
                    {
                        tobj.EQ(bin, (::string)"0b1111011");
                        delete [] bin;
                    }
                    if (tobj.IsNotNull(oct))
                    {
                        tobj.EQ(oct, (::string)"\\0173");
                        delete [] oct;
                    }
                    if (tobj.IsNotNull(dec))
                    {
                        tobj.EQ(dec, (::string)"123");
                        delete [] dec;
                    }
                    if (tobj.IsNotNull(hex))
                    {
                        tobj.EQ(hex, (::string)"0x7B");
                        delete [] hex;
                    }
                    if (tobj.IsNotNull(ndec))
                    {
                        tobj.EQ(ndec, (::string)"-123");
                        delete [] ndec;
                    }
                });
            entity.RunTest("uint16", "format - empty & bin & oct & dec & hex", [](tianyu::test::TestObject& tobj) -> void
                {
                    ::string empty = tianyu::FormatHelper::Format((uint16)123, (::string)"");
                    ::string bin = tianyu::FormatHelper::Format((uint16)123, (::string)"B");
                    ::string oct = tianyu::FormatHelper::Format((uint16)123, (::string)"O");
                    ::string dec = tianyu::FormatHelper::Format((uint16)123, (::string)"d");
                    ::string hex = tianyu::FormatHelper::Format((uint16)123, (::string)"X");
                    ::string ndec = tianyu::FormatHelper::Format((uint16)-123, (::string)"d");

                    if (tobj.IsNotNull(empty))
                    {
                        tobj.EQ(empty, (::string)"123");
                        delete [] empty;
                    }
                    if (tobj.IsNotNull(bin))
                    {
                        tobj.EQ(bin, (::string)"0b1111011");
                        delete [] bin;
                    }
                    if (tobj.IsNotNull(oct))
                    {
                        tobj.EQ(oct, (::string)"\\0173");
                        delete [] oct;
                    }
                    if (tobj.IsNotNull(dec))
                    {
                        tobj.EQ(dec, (::string)"123");
                        delete [] dec;
                    }
                    if (tobj.IsNotNull(hex))
                    {
                        tobj.EQ(hex, (::string)"0x7B");
                        delete [] hex;
                    }
                    if (tobj.IsNotNull(ndec))
                    {
                        tobj.EQ(ndec, (::string)"65413");
                        delete [] ndec;
                    }
                });
            entity.RunTest("int32", "format - empty & bin & oct & dec & hex", [](tianyu::test::TestObject& tobj) -> void
                {
                    ::string empty = tianyu::FormatHelper::Format((int32)123, (::string)"");
                    ::string bin = tianyu::FormatHelper::Format((int32)123, (::string)"B");
                    ::string oct = tianyu::FormatHelper::Format((int32)123, (::string)"O");
                    ::string dec = tianyu::FormatHelper::Format((int32)123, (::string)"d");
                    ::string hex = tianyu::FormatHelper::Format((int32)123, (::string)"X");
                    ::string ndec = tianyu::FormatHelper::Format((int32)-123, (::string)"d");

                    if (tobj.IsNotNull(empty))
                    {
                        tobj.EQ(empty, (::string)"123");
                        delete [] empty;
                    }
                    if (tobj.IsNotNull(bin))
                    {
                        tobj.EQ(bin, (::string)"0b1111011");
                        delete [] bin;
                    }
                    if (tobj.IsNotNull(oct))
                    {
                        tobj.EQ(oct, (::string)"\\0173");
                        delete [] oct;
                    }
                    if (tobj.IsNotNull(dec))
                    {
                        tobj.EQ(dec, (::string)"123");
                        delete [] dec;
                    }
                    if (tobj.IsNotNull(hex))
                    {
                        tobj.EQ(hex, (::string)"0x7B");
                        delete [] hex;
                    }
                    if (tobj.IsNotNull(ndec))
                    {
                        tobj.EQ(ndec, (::string)"-123");
                        delete [] ndec;
                    }
                });
            entity.RunTest("uint32", "format - empty & bin & oct & dec & hex", [](tianyu::test::TestObject& tobj) -> void
                {
                    ::string empty = tianyu::FormatHelper::Format((uint32)123, (::string)"");
                    ::string bin = tianyu::FormatHelper::Format((uint32)123, (::string)"B");
                    ::string oct = tianyu::FormatHelper::Format((uint32)123, (::string)"O");
                    ::string dec = tianyu::FormatHelper::Format((uint32)123, (::string)"d");
                    ::string hex = tianyu::FormatHelper::Format((uint32)123, (::string)"X");
                    ::string ndec = tianyu::FormatHelper::Format((uint32)-123, (::string)"d");

                    if (tobj.IsNotNull(empty))
                    {
                        tobj.EQ(empty, (::string)"123");
                        delete [] empty;
                    }
                    if (tobj.IsNotNull(bin))
                    {
                        tobj.EQ(bin, (::string)"0b1111011");
                        delete [] bin;
                    }
                    if (tobj.IsNotNull(oct))
                    {
                        tobj.EQ(oct, (::string)"\\0173");
                        delete [] oct;
                    }
                    if (tobj.IsNotNull(dec))
                    {
                        tobj.EQ(dec, (::string)"123");
                        delete [] dec;
                    }
                    if (tobj.IsNotNull(hex))
                    {
                        tobj.EQ(hex, (::string)"0x7B");
                        delete [] hex;
                    }
                    if (tobj.IsNotNull(ndec))
                    {
                        tobj.EQ(ndec, (::string)"4294967173");
                        delete [] ndec;
                    }
                });
            entity.RunTest("int64", "format - empty & bin & oct & dec & hex", [](tianyu::test::TestObject& tobj) -> void
                {
                    ::string empty = tianyu::FormatHelper::Format((int64)123, (::string)"");
                    ::string bin = tianyu::FormatHelper::Format((int64)123, (::string)"B");
                    ::string oct = tianyu::FormatHelper::Format((int64)123, (::string)"O");
                    ::string dec = tianyu::FormatHelper::Format((int64)123, (::string)"d");
                    ::string hex = tianyu::FormatHelper::Format((int64)123, (::string)"X");
                    ::string ndec = tianyu::FormatHelper::Format((int64)-123, (::string)"d");

                    if (tobj.IsNotNull(empty))
                    {
                        tobj.EQ(empty, (::string)"123");
                        delete [] empty;
                    }
                    if (tobj.IsNotNull(bin))
                    {
                        tobj.EQ(bin, (::string)"0b1111011");
                        delete [] bin;
                    }
                    if (tobj.IsNotNull(oct))
                    {
                        tobj.EQ(oct, (::string)"\\0173");
                        delete [] oct;
                    }
                    if (tobj.IsNotNull(dec))
                    {
                        tobj.EQ(dec, (::string)"123");
                        delete [] dec;
                    }
                    if (tobj.IsNotNull(hex))
                    {
                        tobj.EQ(hex, (::string)"0x7B");
                        delete [] hex;
                    }
                    if (tobj.IsNotNull(ndec))
                    {
                        tobj.EQ(ndec, (::string)"-123");
                        delete [] ndec;
                    }
                });
            entity.RunTest("uint64", "format - empty & bin & oct & dec & hex", [](tianyu::test::TestObject& tobj) -> void
                {
                    ::string empty = tianyu::FormatHelper::Format((uint64)123, (::string)"");
                    ::string bin = tianyu::FormatHelper::Format((uint64)123, (::string)"B");
                    ::string oct = tianyu::FormatHelper::Format((uint64)123, (::string)"O");
                    ::string dec = tianyu::FormatHelper::Format((uint64)123, (::string)"d");
                    ::string hex = tianyu::FormatHelper::Format((uint64)123, (::string)"X");
                    ::string ndec = tianyu::FormatHelper::Format((uint64)-123, (::string)"d");

                    if (tobj.IsNotNull(empty))
                    {
                        tobj.EQ(empty, (::string)"123");
                        delete [] empty;
                    }
                    if (tobj.IsNotNull(bin))
                    {
                        tobj.EQ(bin, (::string)"0b1111011");
                        delete [] bin;
                    }
                    if (tobj.IsNotNull(oct))
                    {
                        tobj.EQ(oct, (::string)"\\0173");
                        delete [] oct;
                    }
                    if (tobj.IsNotNull(dec))
                    {
                        tobj.EQ(dec, (::string)"123");
                        delete [] dec;
                    }
                    if (tobj.IsNotNull(hex))
                    {
                        tobj.EQ(hex, (::string)"0x7B");
                        delete [] hex;
                    }
                    if (tobj.IsNotNull(ndec))
                    {
                        tobj.EQ(ndec, (::string)"18446744073709551493");
                        delete [] ndec;
                    }
                });
            entity.RunTest("bool", "format - empty & lower & upper & numeric", [](tianyu::test::TestObject& tobj) -> void
                {
                    ::string emptyt = tianyu::FormatHelper::Format(true, (::string)"");
                    ::string emptyf = tianyu::FormatHelper::Format(false, (::string)"");
                    ::string lowert = tianyu::FormatHelper::Format(true, (::string)"u");
                    ::string lowerf = tianyu::FormatHelper::Format(false, (::string)"u");
                    ::string uppert = tianyu::FormatHelper::Format(true, (::string)"U");
                    ::string upperf = tianyu::FormatHelper::Format(false, (::string)"U");

                    ::string hext = tianyu::FormatHelper::Format(true, (::string)"XDD");
                    ::string hexf = tianyu::FormatHelper::Format(false, (::string)"XDD");

                    if (tobj.IsNotNull(emptyt))
                    {
                        tobj.EQ(emptyt, (::string)"true");
                        delete [] emptyt;
                    }
                    if (tobj.IsNotNull(emptyf))
                    {
                        tobj.EQ(emptyf, (::string)"false");
                        delete [] emptyf;
                    }

                    if (tobj.IsNotNull(lowert))
                    {
                        tobj.EQ(lowert, (::string)"true");
                        delete [] lowert;
                    }
                    if (tobj.IsNotNull(lowerf))
                    {
                        tobj.EQ(lowerf, (::string)"false");
                        delete [] lowerf;
                    }

                    if (tobj.IsNotNull(uppert))
                    {
                        tobj.EQ(uppert, (::string)"TRUE");
                        delete [] uppert;
                    }
                    if (tobj.IsNotNull(upperf))
                    {
                        tobj.EQ(upperf, (::string)"FALSE");
                        delete [] upperf;
                    }

                    if (tobj.IsNotNull(hext))
                    {
                        tobj.EQ(hext, (::string)"0x01");
                        delete [] hext;
                    }
                    if (tobj.IsNotNull(hexf))
                    {
                        tobj.EQ(hexf, (::string)"0x00");
                        delete [] hexf;
                    }
                });
            entity.RunTest("decimal", "format - empty & no-empty", [](tianyu::test::TestObject& tobj) -> void
                {
                    ::string emptyf = tianyu::FormatHelper::Format((float)1, (::string)"");
                    ::string emptyd = tianyu::FormatHelper::Format(1.0, (::string)"");

                    ::string nemptyf = tianyu::FormatHelper::Format((float)1, (::string)"D");
                    ::string nemptyd = tianyu::FormatHelper::Format(1.0, (::string)"D");

                    if (tobj.IsNull(emptyf))
                        delete [] emptyf;

                    if (tobj.IsNull(emptyd))
                        delete [] emptyd;

                    if (tobj.IsNull(nemptyf))
                        delete [] nemptyf;

                    if (tobj.IsNull(nemptyd))
                        delete [] nemptyd;
                });
            entity.RunTest("tianyu::IToString", "format", [](tianyu::test::TestObject& tobj) -> void
                {
                    TestClass testClass;
                    ::string format = tianyu::FormatHelper::Format(testClass);

                    if (tobj.IsNotNull(format))
                    {
                        tobj.EQ(format, (::string)"TestClass");
                        delete [] format;
                    }
                });
            entity.RunTest("other data type", "format - empty & no-empty", [](tianyu::test::TestObject& tobj) -> void
                {
                    TestClassNoToString testClass;
                    tianyu::Type<TestClassNoToString> type = tianyu::GetType<TestClassNoToString>();

                    ::string format = tianyu::FormatHelper::Format(testClass);

                    if (tobj.IsNotNull(format))
                    {
                        tobj.EQ(format, type.Name());
                        delete [] format;
                    }
                });
        });

    entity.StartSpec("parse", [](tianyu::test::TestEntity& entity) -> void
        {
            entity.StartSpec("char", [](tianyu::test::TestEntity& entity) -> void
                {
                    entity.RunExceptionTest<tianyu::except::ArgumentNullException>(
                        "null string",
                        "should throw exception",
                        [](tianyu::test::TestObject& tobj) -> void
                        {
                            char value;
                            tianyu::ParseHelper::Parse(::null, value);
                        }
                    );
                    entity.RunExceptionTest<tianyu::except::ParseStringEmptyException>(
                        "empty string",
                        "should throw exception",
                        [](tianyu::test::TestObject& tobj) -> void
                        {
                            char value;
                            tianyu::ParseHelper::Parse((::string)"", value);
                        }
                    );
                    entity.RunTest("string 'abc'", "parse - return char 'a'", [](tianyu::test::TestObject& tobj) -> void
                        {
                            char value;
                            tianyu::ParseHelper::Parse((::string)"abc", value);

                            tobj.EQ(value, 'a');
                        });
                });
            entity.StartSpec("uchar", [](tianyu::test::TestEntity& entity) -> void
                {
                    entity.RunExceptionTest<tianyu::except::ArgumentNullException>(
                        "null string",
                        "should throw exception",
                        [](tianyu::test::TestObject& tobj) -> void
                        {
                            uchar value;
                            tianyu::ParseHelper::Parse(::null, value);
                        }
                    );
                    entity.RunExceptionTest<tianyu::except::ParseStringEmptyException>(
                        "empty string",
                        "should throw exception",
                        [](tianyu::test::TestObject& tobj) -> void
                        {
                            uchar value;
                            tianyu::ParseHelper::Parse((::string)"", value);
                        }
                    );
                    entity.RunTest("string 'abc'", "parse - return char 'a'", [](tianyu::test::TestObject& tobj) -> void
                        {
                            uchar value;
                            tianyu::ParseHelper::Parse((::string)"abc", value);

                            tobj.EQ(value, (uchar)'a');
                        });
                });
            // entity.RunTest("char", "format - empty & no-empty", [](tianyu::test::TestObject& tobj) -> void
            //     {

            //     });

            // due to all the integer type parse functions use the same base core api
            // use int64 and uint64 for full tests and other integer type get the simple verifications.
            entity.StartSpec("integer tests", [](tianyu::test::TestEntity& entity) -> void
                {
                    entity.StartSpec("int64", [](tianyu::test::TestEntity& entity) -> void
                        {
                            entity.StartSpec("exceptions", [](tianyu::test::TestEntity& entity) -> void
                                {
                                    entity.RunExceptionTest<tianyu::except::ArgumentNullException>(
                                        "null string",
                                        "should throw exception",
                                        [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            int64 value = -1;
                                            tianyu::ParseHelper::Parse(::null, value);
                                        }
                                    );
                                    entity.RunExceptionTest<tianyu::except::ParseException>(
                                        "positive negative symbol error",
                                        "should throw exception",
                                        [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            int64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"+-", value);
                                        }
                                    );
                                    entity.RunExceptionTest<tianyu::except::ParseException>(
                                        "positive negative symbol error #2",
                                        "should throw exception",
                                        [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            int64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"\\+", value);
                                        }
                                    );
                                    entity.RunExceptionTest<tianyu::except::ParseException>(
                                        "scale error",
                                        "should throw exception",
                                        [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            int64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"0b\\", value);
                                        }
                                    );

                                    entity.RunExceptionTest<tianyu::except::ParseException>(
                                        "error char",
                                        "should throw exception",
                                        [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            int64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)",", value);
                                        }
                                    );
                                    entity.RunExceptionTest<tianyu::except::ParseException>(
                                        "error char - bin over 0 | 1",
                                        "should throw exception",
                                        [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            int64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"0b2", value);
                                        }
                                    );
                                    entity.RunExceptionTest<tianyu::except::ParseException>(
                                        "error char - oct over 7",
                                        "should throw exception",
                                        [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            int64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"\\8", value);
                                        }
                                    );
                                    entity.RunExceptionTest<tianyu::except::ParseException>(
                                        "error char - dec not in 0-9",
                                        "should throw exception",
                                        [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            int64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"125a", value);
                                        }
                                    );
                                    entity.RunExceptionTest<tianyu::except::ParseException>(
                                        "error char - hex not in 0-9 & a-f",
                                        "should throw exception",
                                        [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            int64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"0x89t", value);
                                        }
                                    );
                                });

                            entity.StartSpec("bin string", [](tianyu::test::TestEntity& entity) -> void
                                {
                                    entity.RunTest("implicit positive symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            int64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"0b11010010", value);

                                            tobj.EQ(value, (int64)210);
                                        });
                                    entity.RunTest("explicit positive symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            int64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"+0b11010010", value);

                                            tobj.EQ(value, (int64)210);
                                        });
                                    entity.RunTest("negative symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            int64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"-0b11010010", value);

                                            tobj.EQ(value, (int64)-210);
                                        });
                                });

                            entity.StartSpec("oct string", [](tianyu::test::TestEntity& entity) -> void
                                {
                                    entity.RunTest("implicit positive symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            int64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"\\123", value);

                                            tobj.EQ(value, (int64)83);
                                        });
                                    entity.RunTest("explicit positive symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            int64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"+\\123", value);

                                            tobj.EQ(value, (int64)83);
                                        });
                                    entity.RunTest("negative symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            int64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"-\\123", value);

                                            tobj.EQ(value, (int64)-83);
                                        });
                                });

                            entity.StartSpec("dec string", [](tianyu::test::TestEntity& entity) -> void
                                {
                                    entity.RunTest("implicit positive symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            int64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"123", value);

                                            tobj.EQ(value, (int64)123);
                                        });
                                    entity.RunTest("explicit positive symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            int64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"+123", value);

                                            tobj.EQ(value, (int64)123);
                                        });
                                    entity.RunTest("negative symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            int64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"-123", value);

                                            tobj.EQ(value, (int64)-123);
                                        });
                                });

                            entity.StartSpec("hex string", [](tianyu::test::TestEntity& entity) -> void
                                {
                                    entity.RunTest("implicit positive symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            int64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"0xAbC4F", value);

                                            tobj.EQ(value, (int64)703567);
                                        });
                                    entity.RunTest("explicit positive symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            int64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"+0xAbC4F", value);

                                            tobj.EQ(value, (int64)703567);
                                        });
                                    entity.RunTest("negative symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            int64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"-0xAbC4F", value);

                                            tobj.EQ(value, (int64)-703567);
                                        });
                                });
                        });
                    entity.StartSpec("uint64", [](tianyu::test::TestEntity& entity) -> void
                        {
                            entity.StartSpec("exceptions", [](tianyu::test::TestEntity& entity) -> void
                                {
                                    entity.RunExceptionTest<tianyu::except::ArgumentNullException>(
                                        "null string",
                                        "should throw exception",
                                        [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            uint64 value = -1;
                                            tianyu::ParseHelper::Parse(::null, value);
                                        }
                                    );
                                    entity.RunExceptionTest<tianyu::except::ParseException>(
                                        "positive negative symbol error",
                                        "should throw exception",
                                        [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            uint64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"+-", value);
                                        }
                                    );
                                    entity.RunExceptionTest<tianyu::except::ParseException>(
                                        "scale error",
                                        "should throw exception",
                                        [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            uint64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"0b\\", value);
                                        }
                                    );

                                    entity.RunExceptionTest<tianyu::except::ParseException>(
                                        "error char",
                                        "should throw exception",
                                        [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            uint64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)",", value);
                                        }
                                    );
                                });

                            entity.StartSpec("bin string", [](tianyu::test::TestEntity& entity) -> void
                                {
                                    entity.RunTest("implicit positive symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            uint64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"0b11010010", value);

                                            tobj.EQ(value, (uint64)210);
                                        });
                                    entity.RunTest("explicit positive symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            uint64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"+0b11010010", value);

                                            tobj.EQ(value, (uint64)210);
                                        });
                                    entity.RunTest("negative symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            uint64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"-0b11010010", value);

                                            tobj.EQ(value, (uint64)210);
                                        });
                                });

                            entity.StartSpec("oct string", [](tianyu::test::TestEntity& entity) -> void
                                {
                                    entity.RunTest("implicit positive symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            uint64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"\\123", value);

                                            tobj.EQ(value, (uint64)83);
                                        });
                                    entity.RunTest("explicit positive symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            uint64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"+\\123", value);

                                            tobj.EQ(value, (uint64)83);
                                        });
                                    entity.RunTest("negative symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            uint64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"-\\123", value);

                                            tobj.EQ(value, (uint64)83);
                                        });
                                });

                            entity.StartSpec("dec string", [](tianyu::test::TestEntity& entity) -> void
                                {
                                    entity.RunTest("implicit positive symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            uint64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"123", value);

                                            tobj.EQ(value, (uint64)123);
                                        });
                                    entity.RunTest("explicit positive symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            uint64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"+123", value);

                                            tobj.EQ(value, (uint64)123);
                                        });
                                    entity.RunTest("negative symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            uint64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"-123", value);

                                            tobj.EQ(value, (uint64)123);
                                        });
                                });

                            entity.StartSpec("hex string", [](tianyu::test::TestEntity& entity) -> void
                                {
                                    entity.RunTest("implicit positive symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            uint64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"0xAbC4F", value);

                                            tobj.EQ(value, (uint64)703567);
                                        });
                                    entity.RunTest("explicit positive symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            uint64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"+0xAbC4F", value);

                                            tobj.EQ(value, (uint64)703567);
                                        });
                                    entity.RunTest("negative symbol", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            uint64 value = -1;
                                            tianyu::ParseHelper::Parse((::string)"-0xAbC4F", value);

                                            tobj.EQ(value, (uint64)703567);
                                        });
                                });
                        });

                    entity.StartSpec("int16", [](tianyu::test::TestEntity& entity) -> void
                        {
                            entity.RunTest("bin", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    int16 value = -1;
                                    tianyu::ParseHelper::Parse((::string)"0b11101010", value);

                                    tobj.EQ(value, (int16)234);
                                });
                            entity.RunTest("oct", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    int16 value = -1;
                                    tianyu::ParseHelper::Parse((::string)"\\123", value);

                                    tobj.EQ(value, (int16)83);
                                });
                            entity.RunTest("dec", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    int16 value = -1;
                                    tianyu::ParseHelper::Parse((::string)"123", value);

                                    tobj.EQ(value, (int16)123);
                                });
                            entity.RunTest("hex", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    int16 value = -1;
                                    tianyu::ParseHelper::Parse((::string)"0xAbC4F", value);

                                    tobj.EQ(value, (int16)48207);
                                });
                        });
                    entity.StartSpec("uint16", [](tianyu::test::TestEntity& entity) -> void
                        {
                            entity.RunTest("bin", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    uint16 value = -1;
                                    tianyu::ParseHelper::Parse((::string)"0b11101010", value);

                                    tobj.EQ(value, (uint16)234);
                                });
                            entity.RunTest("oct", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    uint16 value = -1;
                                    tianyu::ParseHelper::Parse((::string)"\\123", value);

                                    tobj.EQ(value, (uint16)83);
                                });
                            entity.RunTest("dec", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    uint16 value = -1;
                                    tianyu::ParseHelper::Parse((::string)"123", value);

                                    tobj.EQ(value, (uint16)123);
                                });
                            entity.RunTest("hex", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    uint16 value = -1;
                                    tianyu::ParseHelper::Parse((::string)"0xAbC4F", value);

                                    tobj.EQ(value, (uint16)48207);
                                });
                            entity.RunTest("negative", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    uint16 value = -1;
                                    tianyu::ParseHelper::Parse((::string)"-123", value);

                                    tobj.EQ(value, (uint16)123);
                                });
                        });

                    entity.StartSpec("int32", [](tianyu::test::TestEntity& entity) -> void
                        {
                            entity.RunTest("bin", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    int32 value = -1;
                                    tianyu::ParseHelper::Parse((::string)"0b11101010", value);

                                    tobj.EQ(value, (int32)234);
                                });
                            entity.RunTest("oct", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    int32 value = -1;
                                    tianyu::ParseHelper::Parse((::string)"\\123", value);

                                    tobj.EQ(value, (int32)83);
                                });
                            entity.RunTest("dec", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    int32 value = -1;
                                    tianyu::ParseHelper::Parse((::string)"123", value);

                                    tobj.EQ(value, (int32)123);
                                });
                            entity.RunTest("hex", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    int32 value = -1;
                                    tianyu::ParseHelper::Parse((::string)"0xAbC4F", value);

                                    tobj.EQ(value, (int32)703567);
                                });
                        });
                    entity.StartSpec("uint32", [](tianyu::test::TestEntity& entity) -> void
                        {
                            entity.RunTest("bin", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    uint32 value = -1;
                                    tianyu::ParseHelper::Parse((::string)"0b11101010", value);

                                    tobj.EQ(value, (uint32)234);
                                });
                            entity.RunTest("oct", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    uint32 value = -1;
                                    tianyu::ParseHelper::Parse((::string)"\\123", value);

                                    tobj.EQ(value, (uint32)83);
                                });
                            entity.RunTest("dec", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    uint32 value = -1;
                                    tianyu::ParseHelper::Parse((::string)"123", value);

                                    tobj.EQ(value, (uint32)123);
                                });
                            entity.RunTest("hex", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    uint32 value = -1;
                                    tianyu::ParseHelper::Parse((::string)"0xAbC4F", value);

                                    tobj.EQ(value, (uint32)703567);
                                });
                            entity.RunTest("negative", "parse success", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    uint32 value = -1;
                                    tianyu::ParseHelper::Parse((::string)"-123", value);

                                    tobj.EQ(value, (uint32)123);
                                });
                        });
                });

            entity.StartSpec("boolean", [](tianyu::test::TestEntity& entity) -> void
                {
                    entity.RunExceptionTest<tianyu::except::ArgumentNullException>(
                        "null string",
                        "should throw exception",
                        [](tianyu::test::TestObject& tobj) -> void
                        {
                            bool value;
                            tianyu::ParseHelper::Parse(::null, value);
                        }
                    );
                    entity.RunTest("empty string", "format - false", [](tianyu::test::TestObject& tobj) -> void
                        {
                            bool value = true;
                            tianyu::ParseHelper::Parse((::string)"", value);

                            tobj.ToBeFalse(value);
                        });

                    entity.StartSpec("single char", [](tianyu::test::TestEntity& entity) -> void
                        {
                            entity.RunTest("0", "format - false", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    bool value = true;
                                    tianyu::ParseHelper::Parse((::string)"0", value);

                                    tobj.ToBeFalse(value);
                                });
                            entity.RunTest("f", "format - false", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    bool value = true;
                                    tianyu::ParseHelper::Parse((::string)"f", value);

                                    tobj.ToBeFalse(value);
                                });
                            entity.RunTest("F", "format - false", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    bool value = true;
                                    tianyu::ParseHelper::Parse((::string)"F", value);

                                    tobj.ToBeFalse(value);
                                });
                            entity.RunTest("t", "format - true", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    bool value = false;
                                    tianyu::ParseHelper::Parse((::string)"t", value);

                                    tobj.ToBeTrue(value);
                                });
                            entity.RunTest("other char", "format - true", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    bool value = false;
                                    tianyu::ParseHelper::Parse((::string)"a", value);

                                    tobj.ToBeTrue(value);
                                });
                        });

                    entity.StartSpec("false string", [](tianyu::test::TestEntity& entity) -> void
                        {
                            entity.RunTest("lower case", "format - false", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    bool value = true;
                                    tianyu::ParseHelper::Parse((::string)"false", value);

                                    tobj.ToBeFalse(value);
                                });
                            entity.RunTest("upper case", "format - false", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    bool value = true;
                                    tianyu::ParseHelper::Parse((::string)"FALSE", value);

                                    tobj.ToBeFalse(value);
                                });
                            entity.RunTest("mix case", "format - false", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    bool value = true;
                                    tianyu::ParseHelper::Parse((::string)"fAlSE", value);

                                    tobj.ToBeFalse(value);
                                });
                        });

                    entity.StartSpec("other string", [](tianyu::test::TestEntity& entity) -> void
                        {
                            entity.StartSpec("value type", [](tianyu::test::TestEntity& entity) -> void
                                {
                                    entity.RunTest("000", "format - false", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            bool value = true;
                                            tianyu::ParseHelper::Parse((::string)"0", value);

                                            tobj.ToBeFalse(value);
                                        });
                                    entity.RunTest("Pos", "format - true", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            bool value = false;
                                            tianyu::ParseHelper::Parse((::string)"123", value);

                                            tobj.ToBeTrue(value);
                                        });
                                    entity.RunTest("Neg", "format - true", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            bool value = false;
                                            tianyu::ParseHelper::Parse((::string)"-23", value);

                                            tobj.ToBeTrue(value);
                                        });
                                });

                            entity.RunTest("not value type", "format - true", [](tianyu::test::TestObject& tobj) -> void
                                {
                                    bool value = false;
                                    tianyu::ParseHelper::Parse((::string)"467tv", value);

                                    tobj.ToBeTrue(value);
                                });
                        });
                });

            entity.StartSpec("decimal tests", [](tianyu::test::TestEntity& entity) -> void
                {
                    // due to double and float type parse functions use the same base core api
                    // use double for full tests and float get the simple verifications

                    entity.StartSpec("double", [](tianyu::test::TestEntity& entity) -> void
                        {
                            entity.StartSpec("exceptions", [](tianyu::test::TestEntity& entity) -> void
                                {
                                    entity.RunExceptionTest<tianyu::except::ArgumentNullException>(
                                        "null string",
                                        "should throw exception",
                                        [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            double value = -1;
                                            tianyu::ParseHelper::Parse(::null, value);
                                        }
                                    );
                                    entity.RunExceptionTest<tianyu::except::ParseException>(
                                        "pos neg symbol",
                                        "should throw exception",
                                        [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            double value = -1;
                                            tianyu::ParseHelper::Parse((::string)"+-", value);
                                        }
                                    );
                                    entity.RunExceptionTest<tianyu::except::ParseException>(
                                        "exp with no base value",
                                        "should throw exception",
                                        [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            double value = -1;
                                            tianyu::ParseHelper::Parse((::string)"e123", value);
                                        }
                                    );
                                    entity.RunExceptionTest<tianyu::except::ParseException>(
                                        "error char",
                                        "should throw exception",
                                        [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            double value = -1;
                                            tianyu::ParseHelper::Parse((::string)",", value);
                                        }
                                    );
                                });

                            entity.StartSpec("base only", [](tianyu::test::TestEntity& entity) -> void
                                {
                                    entity.RunTest("integer base +", "format", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            double value = -1.0;
                                            tianyu::ParseHelper::Parse((::string)"+123", value);

                                            tobj.EQ(value, (double)123);
                                        });
                                    entity.RunTest("integer base -", "format", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            double value = -1.0;
                                            tianyu::ParseHelper::Parse((::string)"-123", value);

                                            tobj.EQ(value, (double)-123);
                                        });
                                    entity.RunTest("decimal base +", "format", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            double value = -1.0;
                                            tianyu::ParseHelper::Parse((::string)"123.5", value);

                                            tobj.EQ(value, 123.5);
                                        });
                                    entity.RunTest("decimal base -", "format", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            double value = -1.0;
                                            tianyu::ParseHelper::Parse((::string)"-123.5", value);

                                            tobj.EQ(value, -123.5);
                                        });
                                });

                            entity.StartSpec("has exp", [](tianyu::test::TestEntity& entity) -> void
                                {
                                    entity.RunTest("integer base + & exp +", "format", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            double value = -1.0;
                                            tianyu::ParseHelper::Parse((::string)"+123e5", value);

                                            tobj.EQ(value, (double)12300000);
                                        });
                                    entity.RunTest("integer base + & exp -", "format", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            double value = -1.0;
                                            tianyu::ParseHelper::Parse((::string)"+12325e-2", value);

                                            tobj.EQ(value, (double)123.25);
                                        });

                                    entity.RunTest("integer base - & exp +", "format", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            double value = -1.0;
                                            tianyu::ParseHelper::Parse((::string)"-123e5", value);

                                            tobj.EQ(value, (double)-12300000);
                                        });
                                    entity.RunTest("integer base - & exp -", "format", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            double value = -1.0;
                                            tianyu::ParseHelper::Parse((::string)"-12325e-2", value);

                                            tobj.EQ(value, (double)-123.25);
                                        });

                                    entity.RunTest("decimal base + & exp +", "format", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            double value = -1.0;
                                            tianyu::ParseHelper::Parse((::string)"123.5e1", value);

                                            tobj.EQ(value, (double)1235);
                                        });
                                    entity.RunTest("decimal base + & exp -", "format", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            double value = -1.0;
                                            tianyu::ParseHelper::Parse((::string)"12312.5e-2", value);

                                            tobj.EQ(value, 123.125);
                                        });

                                    entity.RunTest("decimal base - & exp +", "format", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            double value = -1.0;
                                            tianyu::ParseHelper::Parse((::string)"-123.5e1", value);

                                            tobj.EQ(value, (double)-1235);
                                        });
                                    entity.RunTest("decimal base - & exp -", "format", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            double value = -1.0;
                                            tianyu::ParseHelper::Parse((::string)"-12312.5e-2", value);

                                            tobj.EQ(value, -123.125);
                                        });
                                });
                        });

                    entity.StartSpec("float", [](tianyu::test::TestEntity& entity) -> void
                        {
                            entity.StartSpec("exceptions", [](tianyu::test::TestEntity& entity) -> void
                                {
                                    entity.RunExceptionTest<tianyu::except::ArgumentNullException>(
                                        "null string",
                                        "should throw exception",
                                        [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            float value = -1;
                                            tianyu::ParseHelper::Parse(::null, value);
                                        }
                                    );
                                    entity.RunExceptionTest<tianyu::except::ParseException>(
                                        "pos neg symbol",
                                        "should throw exception",
                                        [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            float value = -1;
                                            tianyu::ParseHelper::Parse((::string)"+-", value);
                                        }
                                    );
                                    entity.RunExceptionTest<tianyu::except::ParseException>(
                                        "exp with no base value",
                                        "should throw exception",
                                        [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            float value = -1;
                                            tianyu::ParseHelper::Parse((::string)"e123", value);
                                        }
                                    );
                                    entity.RunExceptionTest<tianyu::except::ParseException>(
                                        "error char",
                                        "should throw exception",
                                        [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            float value = -1;
                                            tianyu::ParseHelper::Parse((::string)",", value);
                                        }
                                    );
                                });

                            entity.StartSpec("success", [](tianyu::test::TestEntity& entity) -> void
                                {
                                    entity.RunTest("decimal base + & exp +", "format", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            float value = -1.0;
                                            tianyu::ParseHelper::Parse((::string)"123.5e1", value);

                                            tobj.EQ(value, (float)1235);
                                        });
                                    entity.RunTest("decimal base + & exp -", "format", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            float value = -1.0;
                                            tianyu::ParseHelper::Parse((::string)"12312.5e-2", value);

                                            tobj.EQ(value, (float)123.125);
                                        });

                                    entity.RunTest("decimal base - & exp +", "format", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            float value = -1.0;
                                            tianyu::ParseHelper::Parse((::string)"-123.5e1", value);

                                            tobj.EQ(value, (float)-1235);
                                        });
                                    entity.RunTest("decimal base - & exp -", "format", [](tianyu::test::TestObject& tobj) -> void
                                        {
                                            float value = -1.0;
                                            tianyu::ParseHelper::Parse((::string)"-12312.5e-2", value);

                                            tobj.EQ(value, (float)-123.125);
                                        });
                                });
                        });
                });

            entity.RunExceptionTest<tianyu::except::OperationNotSupportException>(
                "other data type",
                "should throw exception due to not support",
                [](tianyu::test::TestObject& tobj) -> void
                {
                    TestClassNoToString testClass;

                    tianyu::ParseHelper::Parse((::string)"not support", testClass);
                }
            );
        });
}