#include "./lib/cypher-parser.h"

#include <errno.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    cypher_parse_result_t *result = cypher_parse(
            "MATCH (n) RETURN n", NULL, NULL, CYPHER_PARSE_ONLY_STATEMENTS);
    if (result == NULL)
    {
        perror("cypher_parse");
        return EXIT_FAILURE;
    }

    printf("Parsed %d AST nodes\n", cypher_parse_result_nnodes(result));
    printf("Read %d statements\n", cypher_parse_result_ndirectives(result));
    printf("Encountered %d errors\n", cypher_parse_result_nerrors(result));

    cypher_parse_result_free(result);
    return EXIT_SUCCESS;
}
