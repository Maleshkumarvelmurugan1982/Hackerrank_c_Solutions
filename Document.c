#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
char** split_string(const char* str, char delimiter, int* count) {
    int capacity = 10;
    char** tokens = (char**) malloc(capacity * sizeof(char*));
    *count = 0;

    const char* start = str;
    const char* ptr = str;

    while (*ptr) {
        if (*ptr == delimiter) {
            int len = ptr - start;
            char* token = (char*) malloc(len + 1);
            strncpy(token, start, len);
            token[len] = '\0';

            if (*count >= capacity) {
                capacity *= 2;
                tokens = (char**) realloc(tokens, capacity * sizeof(char*));
            }
            tokens[*count] = token;
            (*count)++;

            start = ptr + 1;
        }
        ptr++;
    }

    // last token
    if (start != ptr) {
        int len = ptr - start;
        char* token = (char*) malloc(len + 1);
        strncpy(token, start, len);
        token[len] = '\0';

        if (*count >= capacity) {
            capacity *= 2;
            tokens = (char**) realloc(tokens, capacity * sizeof(char*));
        }
        tokens[*count] = token;
        (*count)++;
    }

    return tokens;
}

// Function to construct document from text
struct document get_document(char* text) {
    struct document doc;
    doc.paragraph_count = 0;
    doc.data = NULL;

    // Split into paragraphs using '\n'
    int paragraph_count = 0;
    char** paragraph_strs = split_string(text, '\n', &paragraph_count);
    // Allocate memory for paragraphs
    doc.data = (struct paragraph*) malloc(paragraph_count * sizeof(struct paragraph));
    doc.paragraph_count = paragraph_count;

    for (int i = 0; i < paragraph_count; i++) {
        // For each paragraph, split into sentences by '.'
        int sentence_count = 0;
        char** sentence_strs = split_string(paragraph_strs[i], '.', &sentence_count);
        // Allocate sentences
        doc.data[i].data = (struct sentence*) malloc(sentence_count * sizeof(struct sentence));
        doc.data[i].sentence_count = sentence_count;

        for (int j = 0; j < sentence_count; j++) {
            // For each sentence, split into words by ' '
            int word_count = 0;
            char** word_strs = split_string(sentence_strs[j], ' ', &word_count);
            // Allocate words
            doc.data[i].data[j].data = (struct word*) malloc(word_count * sizeof(struct word));
            doc.data[i].data[j].word_count = word_count;

            for (int k = 0; k < word_count; k++) {
                // Allocate and copy word data
                int len = strlen(word_strs[k]);
                doc.data[i].data[j].data[k].data = (char*) malloc((len + 1) * sizeof(char));
                strcpy(doc.data[i].data[j].data[k].data, word_strs[k]);
                free(word_strs[k]);
            }
            free(word_strs);
        }
        // Free sentence strings
        for (int s = 0; s < sentence_count; s++) {
            free(sentence_strs[s]);
        }
        free(sentence_strs);
        free(paragraph_strs[i]);
    }
    free(paragraph_strs);
    return doc;
}

// Function to get the kth paragraph
struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k - 1]; // 1-based index
}

// Function to get the kth sentence in the mth paragraph
struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
    return Doc.data[m - 1].data[k - 1]; // 1-based index
}

// Function to get the kth word in the mth sentence of the nth paragraph
struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n - 1].data[m - 1].data[k - 1]; // 1-based index
}

void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}
