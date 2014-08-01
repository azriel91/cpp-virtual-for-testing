# virtual-for-testing

Depending on the activated maven profile, defines the `VIRTUAL_FOR_TESTING` macro to either be `virtual` or nothing. This allows classes to be mockable using gmock for tests, and removing the `virtual` attribute during a release build for optimization. This requires tests to be disabled, which is done by setting the `nar.skip` property to be true.

## Pre-requisites

* g++ 4.8
* [maven 3](http://maven.apache.org/download.cgi)

## Compiling

1. Install the google test library
	1. Download [googletest](https://code.google.com/p/googletest/downloads/list) 1.7.0
	2. Extract the google test library, and drop this [pom.xml](https://github.com/azriel91/cpp-maven-support/blob/master/gtest/pom.xml) into the directory.
	3. In the googletest directory, run ``mvn install``
2. Install the google mock library.
	1. Download [googlemock](https://code.google.com/p/googlemock/downloads/list) 1.7.0
	2. Extract the google mock library, and drop this [pom.xml](https://github.com/azriel91/cpp-maven-support/blob/master/gmock/pom.xml) into the directory.
	3. In the googlemock directory, run ``mvn install``
3. In the repository checkout directory, run ``mvn test``

## Sample Output:

With `mvn test`:

```
...
[INFO] --- nar-maven-plugin:3.1.0:nar-test (default-nar-test) @ virtual-for-testing ---
[INFO] Preparing Nar dependencies
[INFO] Unpacking 4 dependencies to /usr/dev/virtual-for-testing/target/test-nar
[INFO] Copied 0 test resources
[INFO] Running test Test in /usr/dev/virtual-for-testing/target/test-nar/test-reports
[INFO] + cd /usr/dev/virtual-for-testing/target/test-nar/test-reports
[INFO] + /usr/dev/virtual-for-testing/target/test-nar/bin/amd64-Linux-gpp/Test --gtest_output=xml --gtest_color=yes
[INFO] Running main() from gmock_main.cc
[INFO] [==========] Running 1 test from 1 test case.
[INFO] [----------] Global test environment set-up.
[INFO] [----------] 1 test from MyClassTest
[INFO] [ RUN      ] MyClassTest.callsCollaborator
[INFO] [       OK ] MyClassTest.callsCollaborator (0 ms)
[INFO] [----------] 1 test from MyClassTest (0 ms total)
[INFO] 
[INFO] [----------] Global test environment tear-down
[INFO] [==========] 1 test from 1 test case ran. (0 ms total)
[INFO] [  PASSED  ] 1 test.
[INFO] ------------------------------------------------------------------------
[INFO] BUILD SUCCESS
[INFO] ------------------------------------------------------------------------
[INFO] Total time: 8.438s
[INFO] Finished at: Sat Aug 30 09:42:32 NZST 2014
[INFO] Final Memory: 12M/214M
[INFO] ------------------------------------------------------------------------
```

With `mvn test -Drelease`:

```
...
[INFO] --- nar-maven-plugin:3.1.0:nar-test (default-nar-test) @ virtual-for-testing ---
[INFO] Tests are skipped
[INFO] ------------------------------------------------------------------------
[INFO] BUILD SUCCESS
[INFO] ------------------------------------------------------------------------
[INFO] Total time: 4.453s
[INFO] Finished at: Sat Aug 30 09:44:04 NZST 2014
[INFO] Final Memory: 12M/211M
[INFO] ------------------------------------------------------------------------
```
