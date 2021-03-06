/*
 * 

    <Labirinto>
    <Labirinto>
    Copyright (C) <year>  <name of author>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
//#include "CUnit/Automated.h"
//#include "CUnit/Console.h"

#include "labirinto.h"

#include <stdio.h>  // for printf

/* Test Suite setup and cleanup functions: */

//arquivo = "labirinto_test_1";
int totLinhas=10;
int totColunas=36;
int linEntrada=2;
int colEntrada=0;
int linSaida=5;
int colSaida=35;
int linQueijo=3;
int colQUeijo=34;


int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

/************* Test case functions ****************/
void test_baixo(){
    CU_ASSERT_NOT_EQUAL(baixo(),0);
}

void test_direita(){
    CU_ASSERT_NOT_EQUAL(direita(),0);
}

void test_esquerda(){
	CU_ASSERT_NOT_EQUAL(esquerda(),0);
}

/*void test_queijo(){

}
*/

int test_cima(){
    CU_ASSERT_NOT_EQUAL(cima(),0);
}

int test_saida(){
    CU_ASSERT_EQUAL(saida(),1);
}

int test_inicio(){
    CU_ASSERT_EQUAL(inicio(),1);
}

int test_carga() {
    CU_ASSERT_EQUAL(carga(),1);
}

int mock_test(void){
	CU_ASSERT_EQUAL(0,-1);
}

/************* Test Runner Code goes here **************/

int main ( void )
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if ( CUE_SUCCESS != CU_initialize_registry() )
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite( "max_test_suite", init_suite, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
	/*MOCK TEST*/
   if (  (NULL == CU_add_test(pSuite, "Labirinto carregou", test_carga)) ||
         (NULL == CU_add_test(pSuite, "É início", test_inicio)) ||
         (NULL == CU_add_test(pSuite, "verifica saída", test_saida))||
	     (NULL == CU_add_test(pSuite, "Anda cima", test_cima))||
	     (NULL == CU_add_test(pSuite, "Anda baixo", test_baixo))||
	     (NULL == CU_add_test(pSuite, "Anda esquerda", test_esquerda))||
	     (NULL == CU_add_test(pSuite, "Anda direita", test_direita))||
	     (NULL == CU_add_test(pSuite, "Comeu queijo", mock_test))
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   // Run all tests using the basic interface
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   printf("\n");
   CU_basic_show_failures(CU_get_failure_list());
   printf("\n\n");
/*
   // Run all tests using the automated interface
   CU_automated_run_tests();
   CU_list_tests_to_file();

   // Run all tests using the console interface
   CU_console_run_tests();
*/
   /* Clean up registry and return */
   CU_cleanup_registry();
   return CU_get_error();
}
