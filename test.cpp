#include <lib/Buffer.h>
#include <gtest/gtest.h>

TEST(BufferTestSuite, CreateManyTypesStaticTest) {
    BufferStatic<int> buffer_int(15);
    BufferStatic<bool> buffer_bool(15);
    BufferStatic<std::string> buffer_string(15);
    BufferStatic<std::vector<int>> buffer_vector(15);

    ASSERT_TRUE(buffer_int.max_size() == 15);
    ASSERT_TRUE(buffer_bool.max_size() == 15);
    ASSERT_TRUE(buffer_string.max_size() == 15);
    ASSERT_TRUE(buffer_vector.max_size() == 15);
}


TEST(BufferTestSuite, CreateManyTypesDinamicTest) {
    BufferDynamic<int> buffer_int(15);
    BufferDynamic<bool> buffer_bool(15);
    BufferDynamic<std::string> buffer_string(15);
    BufferDynamic<std::vector<int>> buffer_vector(15);

    ASSERT_TRUE(buffer_int.max_size() == 15);
    ASSERT_TRUE(buffer_bool.max_size() == 15);
    ASSERT_TRUE(buffer_string.max_size() == 15);
    ASSERT_TRUE(buffer_vector.max_size() == 15);
}

TEST(BufferTestSuite, ListStaticTest) {
    BufferStatic<int> buffer = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < buffer.size(); ++i) {
        ASSERT_TRUE(buffer[i] == i + 1);
    }
}

TEST(BufferTestSuite, ListDinamicTest) {
    BufferDynamic<int> buffer = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < buffer.size(); ++i) {
        ASSERT_TRUE(buffer[i] == i + 1);
    }
}

TEST(BufferTestSuite, EmptyStaticTest) {
    BufferStatic<int> buffer(10);

    ASSERT_TRUE(buffer.size() == 0);
    ASSERT_TRUE(buffer.empty());
}

TEST(BufferTestSuite, EmptyDinamicTest) {
    BufferStatic<int> buffer(10);

    ASSERT_TRUE(buffer.size() == 0);
    ASSERT_TRUE(buffer.empty());
}

TEST(BufferTestSuite, CompareStaticBufferTest) {
    BufferStatic<int> buffer_1 = {1, 2, 3, 4, 5, 6, 7, 8};
    BufferStatic<int> buffer_2 = {10, 11, 12};

    BufferStatic<int> buffer_3 = {1, 2, 3, 4, 5, 6, 7, 8};
    BufferStatic<int> buffer_4 = {1, 2, 3, 4, 5, 6, 7, 8};

    ASSERT_TRUE(buffer_1 != buffer_2);
    ASSERT_TRUE(buffer_3 == buffer_4);
}

TEST(BufferTestSuite, CompareDinamicBufferTest) {
    BufferDynamic<int> buffer_1 = {1, 2, 3, 4, 5, 6, 7, 8};
    BufferDynamic<int> buffer_2 = {10, 11, 12};

    BufferDynamic<int> buffer_3 = {1, 2, 3, 4, 5, 6, 7, 8};
    BufferDynamic<int> buffer_4 = {1, 2, 3, 4, 5, 6, 7, 8};

    ASSERT_TRUE(buffer_1 != buffer_2);
    ASSERT_TRUE(buffer_3 == buffer_4);
}

TEST(BufferTestSuite, CopyAndAssignmentStaticTest) {

    BufferStatic<int> buffer_1 = {1, 2, 3, 4, 5, 6, 7, 8};
    BufferStatic<int> buffer_2 = {10, 11, 12};

    BufferStatic<int> buffer_3(buffer_1);
    BufferStatic<int> buffer_4;
    buffer_4 = buffer_2;

    ASSERT_TRUE(buffer_3 == buffer_1);
    ASSERT_TRUE(buffer_4 == buffer_2);
}

TEST(BufferTestSuite, CopyAndAssignmentDinamicTest_1) {
    BufferDynamic<int> buffer_1 = {1, 2, 3, 4, 5, 6, 7, 8};
    BufferDynamic<int> buffer_2 = {10, 11, 12};

    BufferDynamic<int> buffer_3(buffer_1);
    BufferDynamic<int> buffer_4;
    buffer_4 = buffer_2;

    ASSERT_TRUE(buffer_3 == buffer_1);
    ASSERT_TRUE(buffer_4 == buffer_2);
}

TEST(BufferTestSuite, IteratorStaticTest) {
    BufferStatic<int> buffer = {1, 2, 3, 4, 5, 6, 7, 8};

    int i = 1;
    for (BufferStatic<int>::iterator it = buffer.begin(); it != buffer.end(); ++it, ++i) {
        ASSERT_TRUE(*it == i);
    }
}

TEST(BufferTestSuite, IteratorDinamicTest) {
    BufferDynamic<int> buffer = {1, 2, 3, 4, 5, 6, 7, 8};

    int i = 1;
    for (BufferDynamic<int>::iterator it = buffer.begin(); it != buffer.end(); ++it, ++i) {
        ASSERT_TRUE(*it == i);
    }
}

TEST(BufferTestSuite, CopyAndAssignmentDinamicTest_2) {
    BufferDynamic<int> buffer_1 = {1, 1, 1, 1};
    BufferDynamic<int> buffer_2 = {10, 11, 12};

    BufferDynamic<int> buffer_3(4, 1);
    BufferDynamic<int> buffer_4(buffer_2.begin(), buffer_2.end());

    ASSERT_TRUE(buffer_3 == buffer_1);
    ASSERT_TRUE(buffer_4 == buffer_2);
}

TEST(BufferTestSuite, PushStaticTest_1) {
    BufferStatic<int> buffer(10);
    for (int i = 0; i < 5; ++i) {
        buffer.push(i);
    }

    int i = 0;
    for (BufferStatic<int>::iterator it = buffer.begin(); it != buffer.end(); ++it, ++i) {
        ASSERT_TRUE(*it == i);
    }

    ASSERT_TRUE(buffer.size() == 5);
    ASSERT_TRUE(buffer.max_size() == 10);
}

TEST(BufferTestSuite, PushDinamicTest_1) {
    BufferDynamic<int> buffer(10);
    for (int i = 0; i < 5; ++i) {
        buffer.push(i);
    }

    int i = 0;
    for (BufferDynamic<int>::iterator it = buffer.begin(); it != buffer.end(); ++it, ++i) {
        ASSERT_TRUE(*it == i);
    }

    ASSERT_TRUE(buffer.size() == 5);
    ASSERT_TRUE(buffer.max_size() == 10);

}

TEST(BufferTestSuite, PushStaticTest_2) {
    BufferStatic<int> buffer(4);
    for (int i = 0; i < 12; ++i) {
        buffer.push(i);
    }

    for (int i = 0; i < 4; ++i) {
        ASSERT_TRUE(buffer[i] == i + 8);
    }

    ASSERT_TRUE(buffer.size() == 4);
    ASSERT_TRUE(buffer.max_size() == 4);
    ASSERT_TRUE(buffer.empty() == false);

}

TEST(BufferTestSuite, PushDinamicTest_2) {
    BufferDynamic<int> buffer(4);
    for (int i = 0; i < 12; ++i) {
        buffer.push(i);
    }

    for (int i = 0; i < 12; ++i) {
        ASSERT_TRUE(buffer[i] == i);
    }

    ASSERT_TRUE(buffer.size() == 12);
    ASSERT_TRUE(buffer.max_size() == 16);
    ASSERT_TRUE(buffer.empty() == false);
}

TEST(BufferTestSuite, PopStaticTest_1) {
    BufferStatic<int> buffer = {1, 2, 3, 4, 5, 6};
    buffer.pop();
    buffer.pop();
    buffer.pop();

    for (int i = 4; i < 7; ++i) {
        ASSERT_TRUE(buffer[i - 4] == i);
    }

    ASSERT_TRUE(buffer.size() == 3);
    ASSERT_TRUE(buffer.max_size() == 6);
}

TEST(BufferTestSuite, PopDinamicTest_1) {
    BufferDynamic<int> buffer = {1, 2, 3, 4, 5, 6};
    buffer.pop();
    buffer.pop();
    buffer.pop();

    for (int i = 4; i < 7; ++i) {
        ASSERT_TRUE(buffer[i - 4] == i);
    }

    ASSERT_TRUE(buffer.size() == 3);
    ASSERT_TRUE(buffer.max_size() == 6);
}

TEST(BufferTestSuite, PopStaticTest_2) {
    BufferStatic<int> buffer = {1, 2, 3};
    buffer.pop();
    buffer.pop();
    buffer.pop();

    ASSERT_TRUE(buffer.size() == 0);
    ASSERT_TRUE(buffer.max_size() == 3);
    ASSERT_TRUE(buffer.empty() == true);
}

TEST(BufferTestSuite, PopDinamicTest_2) {
    BufferDynamic<int> buffer = {1, 2, 3};
    buffer.pop();
    buffer.pop();
    buffer.pop();

    ASSERT_TRUE(buffer.size() == 0);
    ASSERT_TRUE(buffer.max_size() == 3);
    ASSERT_TRUE(buffer.empty() == true);
}


TEST(BufferTestSuite, PushAndPopStaticBufferTest) {
    BufferStatic<int> buffer = {1, 2, 3, 4};
    buffer.pop();
    buffer.pop();
    buffer.push(5);
    buffer.push(6);

    for (int i = 0; i < 4; ++i) {
        ASSERT_TRUE(buffer[i] == i + 3);
    }
}

TEST(BufferTestSuite, PushAndPopDinamicBufferTest_1) {
    BufferDynamic<int> buffer = {1, 2, 3, 4};
    buffer.pop();
    buffer.pop();
    buffer.push(5);
    buffer.push(6);

    for (int i = 0; i < 4; ++i) {
        ASSERT_TRUE(buffer[i] == i + 3);
    }
}

TEST(BufferTestSuite, PushAndPopDinamicBufferTest_2) {
    BufferDynamic<int> buffer;

    for (int i = 0; i < 3; ++i) {
        buffer.push(i);
    }

    for (int i = 0; i < 3; ++i) {
        buffer.pop();
    }

    for (int i = 0; i < 5; ++i) {
        buffer.push(i);
    }

    for (int i = 0; i < 5; ++i) {
        ASSERT_TRUE(buffer[i] == i);
    }

    ASSERT_TRUE(buffer.size() == 5);
}

TEST(BufferTestSuite, SwapStaticTest) {
    BufferStatic<int> buffer_1 = {10, 20, 30};
    BufferStatic<int> buffer_2 = {40, 50, 60};
    buffer_1.swap(buffer_2);

    for (int i = 0; i < buffer_1.size(); i = i + 10) {
        ASSERT_TRUE(buffer_1[i] == i + 40);
    }

    for (int i = 0; i < buffer_2.size(); i = i + 10) {
        ASSERT_TRUE(buffer_2[i] == i + 10);
    }
}

TEST(BufferTestSuite, InsertDinamicBuffer_1) {
    BufferDynamic<int> buffer_1 = {1, 3, 4, 5, 6};
    BufferDynamic<int>::iterator iter = buffer_1.insert(0, 2);

    BufferDynamic<int> buffer_2 = {1, 2, 3, 4, 5, 6};
    ASSERT_TRUE(buffer_1 == buffer_2);
    ASSERT_TRUE(*iter == 2);
}

TEST(BufferTestSuite, InsertDinamicBuffer_2) {
    BufferDynamic<int> buffer_1 = {1, 2, 2, 4, 4, 4, 4, 4};
    BufferDynamic<int>::iterator iter = buffer_1.insert(2, 3, 3);
    BufferDynamic<int> buffer_2 = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4};
    ASSERT_TRUE(buffer_1 == buffer_2);
    ASSERT_TRUE(*iter == 3);
}

TEST(BufferTestSuite, InsertDinamicBuffer_3) {
    BufferDynamic<int> buffer_1 = {1, 2, 3, 4, 8, 9, 10};
    BufferDynamic<int>::iterator iter = buffer_1.insert(3, {5, 6, 7});
    BufferDynamic<int> buffer_2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ASSERT_TRUE(buffer_1 == buffer_2);
    ASSERT_TRUE(*iter == 5);
}

TEST(BufferTestSuite, AssignDinamicBuffer_1) {
    BufferDynamic<int> buffer_1;
    buffer_1.assign(5, 5);
    BufferDynamic<int> buffer_2 = {5, 5, 5, 5, 5};

    ASSERT_TRUE(buffer_1 == buffer_2);
}

TEST(BufferTestSuite, AssignDinamicBuffer_2) {
    BufferDynamic<int> buffer_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BufferDynamic<int> buffer_2 = {0, 0, 0, 0, 0, 0, 0};


    buffer_2.assign(buffer_1.begin()[0], buffer_1.begin()[5]);
    BufferDynamic<int> buffer_3 = {1, 2, 3, 4, 5};

    ASSERT_TRUE(buffer_2 == buffer_3);
}

TEST(BufferTestSuite, AssignDinamicBuffer_3) {
    BufferDynamic<int> buffer_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    buffer_1.assign({100, 101, 102});
    BufferDynamic<int> buffer_2 = {100, 101, 102};
    ASSERT_TRUE(buffer_1 == buffer_2);
}

TEST(BufferTestSuite, ClearExtBuffer) {
    BufferDynamic<int> buffer = {1, 2, 3, 4, 5};
    buffer.clear();
    ASSERT_TRUE(buffer.empty());
}

TEST(BufferTestSuite, SortBuffer) {
    BufferDynamic<int> buffer = {2, 1, 5, 4, 3};
    sort(buffer.begin(), buffer.end());

    int i = 1;
    for (int& elem: buffer) {
        ASSERT_EQ(i++, elem);
    }
}

TEST(BufferTestSuite, FindBuffer) {
    BufferDynamic<int> buffer = {2, 1, 5, 4, 3};
    auto it = find(buffer.begin(), buffer.end(), 4);

    ASSERT_EQ(*it, 4);
}
