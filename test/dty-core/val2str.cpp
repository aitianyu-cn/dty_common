#include "../testframe.hxx"

TEST_MAIN("dty.common.native.test.dty-core.value_to_string")
{
    entity.StartSpec("exceptions", [](dty::test::TestEntity& entity) -> void
        {
            const int32 _test_ty_base_number_string_convertion_formatter_error_duplicate_scale = -1;
            const int32 _test_ty_base_number_string_convertion_formatter_error_duplicate_prefix = -2;
            const int32 _test_ty_base_number_string_convertion_formatter_error_duplicate_count_i = -3;
            const int32 _test_ty_base_number_string_convertion_formatter_error_duplicate_count_f = -4;
            const int32 _test_ty_base_number_string_convertion_formatter_error_duplicate_count_t = -5;
            const int32 _test_ty_base_number_string_convertion_formatter_error_duplicate_align = -6;
            const int32 _test_ty_base_number_string_convertion_formatter_error_duplicate_sym_force = -7;
            const int32 _test_ty_base_number_string_convertion_formatter_error_duplicate_char_case = -8;
            const int32 _test_ty_base_number_string_convertion_formatter_error_duplicate_fill_char = -9;
            const int32 _test_ty_base_number_string_convertion_formatter_error_fill_char_not_assign = -10;

            entity.RunTest("scale", "duplicate scale", [&](dty::test::TestObject& tobj) -> void
                {
                    try
                    {
                        ::string result = ::l2str_f(0, (::string)"bb");
                    }
                    catch (int32 error_code)
                    {
                        tobj.EQ(error_code, _test_ty_base_number_string_convertion_formatter_error_duplicate_scale);
                    }
                });
            entity.RunTest("prefix", "duplicate prefix", [&](dty::test::TestObject& tobj) -> void
                {
                    try
                    {
                        ::string result = ::l2str_f(0, (::string)"pp");
                    }
                    catch (int32 error_code)
                    {
                        tobj.EQ(error_code, _test_ty_base_number_string_convertion_formatter_error_duplicate_prefix);
                    }
                });
            entity.RunTest("count integer", "duplicate count integer", [&](dty::test::TestObject& tobj) -> void
                {
                    try
                    {
                        ::string result = ::l2str_f(0, (::string)"DDDxDDDDD");
                    }
                    catch (int32 error_code)
                    {
                        tobj.EQ(error_code, _test_ty_base_number_string_convertion_formatter_error_duplicate_count_i);
                    }
                });
            entity.RunTest("count decimal", "duplicate count decimal", [&](dty::test::TestObject& tobj) -> void
                {
                    try
                    {
                        ::string result = ::l2str_f(0, (::string)"fffxfffff");
                    }
                    catch (int32 error_code)
                    {
                        tobj.EQ(error_code, _test_ty_base_number_string_convertion_formatter_error_duplicate_count_f);
                    }
                });
            entity.RunTest("align", "duplicate align", [&](dty::test::TestObject& tobj) -> void
                {
                    try
                    {
                        ::string result = ::l2str_f(0, (::string)"RL");
                    }
                    catch (int32 error_code)
                    {
                        tobj.EQ(error_code, _test_ty_base_number_string_convertion_formatter_error_duplicate_align);
                    }
                });
            entity.RunTest("force symbol", "duplicate force symbol", [&](dty::test::TestObject& tobj) -> void
                {
                    try
                    {
                        ::string result = ::l2str_f(0, (::string)"ss");
                    }
                    catch (int32 error_code)
                    {
                        tobj.EQ(error_code, _test_ty_base_number_string_convertion_formatter_error_duplicate_sym_force);
                    }
                });
            entity.RunTest("char case", "duplicate char case", [&](dty::test::TestObject& tobj) -> void
                {
                    try
                    {
                        ::string result = ::l2str_f(0, (::string)"uU");
                    }
                    catch (int32 error_code)
                    {
                        tobj.EQ(error_code, _test_ty_base_number_string_convertion_formatter_error_duplicate_char_case);
                    }
                });
            entity.RunTest("fill char", "duplicate fill char", [&](dty::test::TestObject& tobj) -> void
                {
                    try
                    {
                        ::string result = ::l2str_f(0, (::string)"r0r1");
                    }
                    catch (int32 error_code)
                    {
                        tobj.EQ(error_code, _test_ty_base_number_string_convertion_formatter_error_duplicate_fill_char);
                    }
                });
            entity.RunTest("fill char", "not have fill char", [&](dty::test::TestObject& tobj) -> void
                {
                    try
                    {
                        ::string result = ::l2str_f(0, (::string)"r");
                    }
                    catch (int32 error_code)
                    {
                        tobj.EQ(error_code, _test_ty_base_number_string_convertion_formatter_error_fill_char_not_assign);
                    }
                });
        });

    entity.StartSpec("Integer Base Type", [](dty::test::TestEntity& entity) -> void
        {
            // due to all of the integer base type use the same logic to process the value
            // to test uint64 and int64 type to cover all types tests

            entity.StartSpec("int64", [](dty::test::TestEntity& entity) -> void
                {
                    entity.RunTest("no formatter", "get default result Positive", [](dty::test::TestObject& tobj) -> void
                        {
                            ::string result = ::l2str_f(123456LL, (::string)"");
                            if (tobj.IsNotNull(result))
                            {
                                tobj.EQ(result, (::string)"123456");
                                delete [] result;
                            }
                            result = ::l2str_f(-123456LL, (::string)"");
                            if (tobj.IsNotNull(result))
                            {
                                tobj.EQ(result, (::string)"-123456");
                                delete [] result;
                            }
                        });
                    entity.RunTest("char formatter", "get default result Positive", [](dty::test::TestObject& tobj) -> void
                        {
                            ::string result = ::l2str_f(123456LL, (::string)"c");
                            char res1format[4];
                            res1format[0] = 1;
                            res1format[1] = -30;
                            res1format[2] = 64;
                            res1format[3] = 0;
                            if (tobj.IsNotNull(result))
                            {
                                tobj.EQ(result, res1format);
                                delete [] result;
                            }

                            char res2format[5];
                            res2format[0] = '-';
                            res2format[1] = 1;
                            res2format[2] = -30;
                            res2format[3] = 64;
                            res2format[4] = 0;
                            result = ::l2str_f(-123456LL, (::string)"c");
                            if (tobj.IsNotNull(result))
                            {
                                tobj.EQ(result, res2format);
                                delete [] result;
                            }
                        });

                    entity.StartSpec("bin formatter", [](dty::test::TestEntity& entity) -> void
                        {
                            entity.StartSpec("prefix", [](dty::test::TestEntity& entity) -> void
                                {
                                    entity.RunTest("b", "not have prefix", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"b");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"11110001001000000");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(-123456LL, (::string)"b");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-11110001001000000");
                                                delete [] result;
                                            }
                                        });
                                    entity.RunTest("B", "has prefix", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"B");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, "0b11110001001000000");
                                                delete [] result;
                                            }
                                            result = ::l2str_f(-123456LL, (::string)"B");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-0b11110001001000000");
                                                delete [] result;
                                            }
                                        });
                                    entity.RunTest("bP", "has prefix", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"bP");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"0b11110001001000000");
                                                delete [] result;
                                            }
                                            result = ::l2str_f(-123456LL, (::string)"bP");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-0b11110001001000000");
                                                delete [] result;
                                            }
                                        });
                                    entity.RunTest("Bp", "not have prefix", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"Bp");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"11110001001000000");
                                                delete [] result;
                                            }
                                            result = ::l2str_f(-123456LL, (::string)"Bp");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-11110001001000000");
                                                delete [] result;
                                            }
                                        });
                                    entity.RunTest("Bu & BU", "has prefix [lower & upper case]", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"Bu");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, "0b11110001001000000");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(123456LL, (::string)"BU");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"0B11110001001000000");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(-123456LL, (::string)"Bu");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-0b11110001001000000");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(-123456LL, (::string)"BU");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-0B11110001001000000");
                                                delete [] result;
                                            }
                                        });
                                    entity.RunTest("bPu & bPU", "has prefix [lower & upper case]", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"bPu");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"0b11110001001000000");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(123456LL, (::string)"bPU");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"0B11110001001000000");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(-123456LL, (::string)"bPu");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-0b11110001001000000");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(-123456LL, (::string)"bPU");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-0B11110001001000000");
                                                delete [] result;
                                            }
                                        });
                                });


                            entity.StartSpec("pre-symbol", [](dty::test::TestEntity& entity) -> void
                                {
                                    entity.RunTest("bs", "has pre-symbol", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"bs");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"+11110001001000000");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(-123456LL, (::string)"bs");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-11110001001000000");
                                                delete [] result;
                                            }
                                        });
                                    entity.RunTest("bsP", "has pre-symbol & prefix", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"bsP");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"+0b11110001001000000");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(-123456LL, (::string)"bsP");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-0b11110001001000000");
                                                delete [] result;
                                            }
                                        });
                                    entity.RunTest("bsPU", "has pre-symbol & prefix & upper case", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"bsPU");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"+0B11110001001000000");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(-123456LL, (::string)"bsPU");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-0B11110001001000000");
                                                delete [] result;
                                            }
                                        });
                                    entity.RunTest("Bs", "has pre-symbol & prefix", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"Bs");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"+0b11110001001000000");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(-123456LL, (::string)"Bs");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-0b11110001001000000");
                                                delete [] result;
                                            }
                                        });
                                    entity.RunTest("BsU", "has pre-symbol & prefix & upper case", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"BsU");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"+0B11110001001000000");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(-123456LL, (::string)"BsU");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-0B11110001001000000");
                                                delete [] result;
                                            }
                                        });
                                });
                        });

                    entity.StartSpec("oct formatter", [](dty::test::TestEntity& entity) -> void
                        {
                            entity.StartSpec("prefix", [](dty::test::TestEntity& entity) -> void
                                {
                                    entity.RunTest("o", "not have prefix", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"o");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"361100");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(-123456LL, (::string)"o");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-361100");
                                                delete [] result;
                                            }
                                        });
                                    entity.RunTest("O", "has prefix", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"O");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"\\0361100");
                                                delete [] result;
                                            }
                                            result = ::l2str_f(-123456LL, (::string)"O");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-\\0361100");
                                                delete [] result;
                                            }
                                        });
                                    entity.RunTest("oP", "has prefix", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"oP");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"\\0361100");
                                                delete [] result;
                                            }
                                            result = ::l2str_f(-123456LL, (::string)"oP");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-\\0361100");
                                                delete [] result;
                                            }
                                        });
                                    entity.RunTest("Op", "not have prefix", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"Op");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"361100");
                                                delete [] result;
                                            }
                                            result = ::l2str_f(-123456LL, (::string)"Op");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-361100");
                                                delete [] result;
                                            }
                                        });
                                });


                            entity.StartSpec("pre-symbol", [](dty::test::TestEntity& entity) -> void
                                {
                                    entity.RunTest("os", "has pre-symbol", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"os");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"+361100");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(-123456LL, (::string)"os");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-361100");
                                                delete [] result;
                                            }
                                        });
                                    entity.RunTest("osP", "has pre-symbol & prefix", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"osP");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"+\\0361100");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(-123456LL, (::string)"osP");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-\\0361100");
                                                delete [] result;
                                            }
                                        });
                                    entity.RunTest("Os", "has pre-symbol & prefix", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"Os");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"+\\0361100");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(-123456LL, (::string)"Os");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-\\0361100");
                                                delete [] result;
                                            }
                                        });
                                });
                        });

                    entity.StartSpec("dec formatter", [](dty::test::TestEntity& entity) -> void
                        {
                            entity.StartSpec("prefix", [](dty::test::TestEntity& entity) -> void
                                {
                                    entity.RunTest("d", "not have prefix", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"d");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"123456");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(-123456LL, (::string)"d");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-123456");
                                                delete [] result;
                                            }
                                        });
                                    entity.RunTest("dP", "not have prefix", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"dP");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"123456");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(-123456LL, (::string)"dP");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-123456");
                                                delete [] result;
                                            }
                                        });
                                });


                            entity.StartSpec("pre-symbol", [](dty::test::TestEntity& entity) -> void
                                {
                                    entity.RunTest("ds", "has pre-symbol", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"ds");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"+123456");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(-123456LL, (::string)"ds");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-123456");
                                                delete [] result;
                                            }
                                        });
                                });
                        });

                    entity.StartSpec("hex formatter", [](dty::test::TestEntity& entity) -> void
                        {
                            entity.StartSpec("prefix", [](dty::test::TestEntity& entity) -> void
                                {
                                    entity.RunTest("x", "default", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"x");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"0x1e240");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(-123456LL, (::string)"x");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-0x1e240");
                                                delete [] result;
                                            }
                                        });
                                    entity.RunTest("X", "default & value upper case", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"X");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"0x1E240");
                                                delete [] result;
                                            }
                                            result = ::l2str_f(-123456LL, (::string)"X");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-0x1E240");
                                                delete [] result;
                                            }
                                        });
                                    entity.RunTest("xp", "not have prefix", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"xp");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"1e240");
                                                delete [] result;
                                            }
                                            result = ::l2str_f(-123456LL, (::string)"xp");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-1e240");
                                                delete [] result;
                                            }
                                        });
                                    entity.RunTest("Xp", "not have prefix & value upper case", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"Xp");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"1E240");
                                                delete [] result;
                                            }
                                            result = ::l2str_f(-123456LL, (::string)"Xp");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-1E240");
                                                delete [] result;
                                            }
                                        });
                                    entity.RunTest("Xu & XU", "has prefix [lower & upper case]", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"Xu");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"0x1e240");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(123456LL, (::string)"XU");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"0x1E240");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(-123456LL, (::string)"Xu");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-0x1e240");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(-123456LL, (::string)"XU");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-0x1E240");
                                                delete [] result;
                                            }
                                        });
                                });


                            entity.StartSpec("pre-symbol", [](dty::test::TestEntity& entity) -> void
                                {
                                    entity.RunTest("xs", "has pre-symbol [lower case]", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"xs");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"+0x1e240");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(-123456LL, (::string)"xs");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-0x1e240");
                                                delete [] result;
                                            }
                                        });
                                    entity.RunTest("Xs", "has pre-symbol [upper case]", [](dty::test::TestObject& tobj) -> void
                                        {
                                            ::string result = ::null;

                                            result = ::l2str_f(123456LL, (::string)"Xs");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"+0x1E240");
                                                delete [] result;
                                            }

                                            result = ::l2str_f(-123456LL, (::string)"Xs");
                                            if (tobj.IsNotNull(result))
                                            {
                                                tobj.EQ(result, (::string)"-0x1E240");
                                                delete [] result;
                                            }
                                        });
                                });
                        });
                });

            entity.StartSpec("uint64", [](dty::test::TestEntity& entity) -> void
                {
                    entity.RunTest("no formatter", "should correct", [](dty::test::TestObject& tobj) -> void
                        {
                            ::string result = ::ul2str_f(123456ULL, (::string)"");
                            if (tobj.IsNotNull(result))
                            {
                                tobj.EQ(result, (::string)"123456");
                                delete [] result;
                            }
                            result = ::ul2str_f(-123456ULL, (::string)"");
                            if (tobj.IsNotNull(result))
                            {
                                tobj.EQ(result, (::string)"18446744073709428160");
                                delete [] result;
                            }
                        });
                    entity.RunTest("bin", "should correct", [](dty::test::TestObject& tobj) -> void
                        {
                            ::string result = ::ul2str_f(123456ULL, (::string)"B");
                            if (tobj.IsNotNull(result))
                            {
                                tobj.EQ(result, "0b11110001001000000");
                                delete [] result;
                            }
                        });
                    entity.RunTest("oct", "should correct", [](dty::test::TestObject& tobj) -> void
                        {
                            ::string result = ::ul2str_f(123456ULL, (::string)"O");
                            if (tobj.IsNotNull(result))
                            {
                                tobj.EQ(result, (::string)"\\0361100");
                                delete [] result;
                            }
                        });
                    entity.RunTest("dec", "should correct", [](dty::test::TestObject& tobj) -> void
                        {
                            ::string result = ::ul2str_f(123456ULL, (::string)"d");
                            if (tobj.IsNotNull(result))
                            {
                                tobj.EQ(result, (::string)"123456");
                                delete [] result;
                            }
                        });
                    entity.RunTest("hex", "should correct", [](dty::test::TestObject& tobj) -> void
                        {
                            ::string result = ::ul2str_f(123456ULL, (::string)"X");
                            if (tobj.IsNotNull(result))
                            {
                                tobj.EQ(result, (::string)"0x1E240");
                                delete [] result;
                            }
                        });
                });

            entity.StartSpec("left align", [](dty::test::TestEntity& entity) -> void
                {
                    entity.RunTest("L", "not align", [](dty::test::TestObject& tobj) -> void
                        {
                            ::string result = ::l2str_f(8ULL, (::string)"L");
                            if (tobj.IsNotNull(result))
                            {
                                tobj.EQ(result, (::string)"8");
                                delete [] result;
                            }
                            result = ::l2str_f(-8ULL, (::string)"L");
                            if (tobj.IsNotNull(result))
                            {
                                tobj.EQ(result, (::string)"-8");
                                delete [] result;
                            }
                        });
                    entity.RunTest("LDDD", "align", [](dty::test::TestObject& tobj) -> void
                        {
                            ::string result = ::l2str_f(8ULL, (::string)"LDDD");
                            if (tobj.IsNotNull(result))
                            {
                                tobj.EQ(result, (::string)"8  ");
                                delete [] result;
                            }
                            result = ::l2str_f(-8ULL, (::string)"LDDD");
                            if (tobj.IsNotNull(result))
                            {
                                tobj.EQ(result, (::string)"-8 ");
                                delete [] result;
                            }
                        });
                });

            entity.StartSpec("right align", [](dty::test::TestEntity& entity) -> void
                {
                    entity.RunTest("R", "not align", [](dty::test::TestObject& tobj) -> void
                        {
                            ::string result = ::l2str_f(8ULL, (::string)"R");
                            if (tobj.IsNotNull(result))
                            {
                                tobj.EQ(result, (::string)"8");
                                delete [] result;
                            }
                            result = ::l2str_f(-8ULL, (::string)"R");
                            if (tobj.IsNotNull(result))
                            {
                                tobj.EQ(result, (::string)"-8");
                                delete [] result;
                            }
                        });
                    entity.RunTest("RDDD", "align", [](dty::test::TestObject& tobj) -> void
                        {
                            ::string result = ::l2str_f(8ULL, (::string)"RDDD");
                            if (tobj.IsNotNull(result))
                            {
                                tobj.EQ(result, (::string)"008");
                                delete [] result;
                            }
                            result = ::l2str_f(-8ULL, (::string)"RDDD");
                            if (tobj.IsNotNull(result))
                            {
                                tobj.EQ(result, (::string)"-08");
                                delete [] result;
                            }
                        });
                    entity.RunTest("RDDDs", "align", [](dty::test::TestObject& tobj) -> void
                        {
                            ::string result = ::l2str_f(8ULL, (::string)"RDDDs");
                            if (tobj.IsNotNull(result))
                            {
                                tobj.EQ(result, (::string)"+08");
                                delete [] result;
                            }
                            result = ::l2str_f(-8ULL, (::string)"RDDDs");
                            if (tobj.IsNotNull(result))
                            {
                                tobj.EQ(result, (::string)"-08");
                                delete [] result;
                            }
                        });
                    entity.RunTest("RDDDsr ", "align", [](dty::test::TestObject& tobj) -> void
                        {
                            ::string result = ::l2str_f(8ULL, (::string)"RDDDsr ");
                            if (tobj.IsNotNull(result))
                            {
                                tobj.EQ(result, (::string)"+ 8");
                                delete [] result;
                            }
                            result = ::l2str_f(-8ULL, (::string)"RDDDsr ");
                            if (tobj.IsNotNull(result))
                            {
                                tobj.EQ(result, (::string)"- 8");
                                delete [] result;
                            }
                        });
                });
        });

    entity.StartSpec("Decimal Base Type", [](dty::test::TestEntity& entity) -> void
        {
            entity.StartSpec("float", [](dty::test::TestEntity& entity) -> void
                {
                    entity.RunTest("no formatter", "should get null value as return", [](dty::test::TestObject& tobj) -> void
                        {
                            float value = 123;

                            ::string result = ::f2str(value);

                            if (!tobj.IsNull(result))
                                delete [] result;
                        });
                    entity.RunTest("has formatter", "should get null value as return", [](dty::test::TestObject& tobj) -> void
                        {
                            float value = 123;

                            ::string result = ::f2str_f(value, (::string)"DDDffff");

                            if (!tobj.IsNull(result))
                                delete [] result;
                        });
                });

            entity.StartSpec("double", [](dty::test::TestEntity& entity) -> void
                {
                    entity.RunTest("no formatter", "should get null value as return", [](dty::test::TestObject& tobj) -> void
                        {
                            double value = 123.0;

                            ::string result = ::d2str(value);

                            if (!tobj.IsNull(result))
                                delete [] result;
                        });
                    entity.RunTest("has formatter", "should get null value as return", [](dty::test::TestObject& tobj) -> void
                        {
                            double value = 123.0;

                            ::string result = ::d2str_f(value, (::string)"DDDffff");

                            if (!tobj.IsNull(result))
                                delete [] result;
                        });
                });
        });
}