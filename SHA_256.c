#include <openssl/evp.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char value[256];
  unsigned char buff[EVP_MAX_MD_SIZE];
  unsigned int buff_len;

  EVP_MD_CTX *ctx = EVP_MD_CTX_new();

  printf("Enter your value to be encrypted: ");
  fgets(value, sizeof(value), stdin);
  value[strcspn(value, "\n")] = '\0';

  EVP_DigestInit_ex(ctx, EVP_sha256(), NULL);
  EVP_DigestUpdate(ctx, value, strlen(value));
  EVP_DigestFinal(ctx, buff, &buff_len);

  printf("The hash is: ");
  for (int i = 0; i < buff_len; i++) {
    printf("%02x", buff[i]);
  }
  printf("\n");
  return 0;
}
