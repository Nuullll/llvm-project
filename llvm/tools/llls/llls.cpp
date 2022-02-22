#include "ClangdLSPServer.h"
#include "Transport.h"
#include "support/ThreadsafeFS.h"
#include "llvm/Support/Program.h"

int main(int argc, char **argv) {
  // Initialize and run ClangdLSPServer.
  // Change stdin to binary to not lose \r\n on windows.
  llvm::sys::ChangeStdinToBinary();
  std::unique_ptr<clang::clangd::Transport> TransportLayer =
      clang::clangd::newJSONTransport(
          stdin, llvm::outs(), &llvm::dbgs(), true,
          clang::clangd::JSONStreamStyle::Delimited);
  clang::clangd::RealThreadsafeFS TFS;
  clang::clangd::ClangdLSPServer::Options Opts;
  clang::clangd::ClangdLSPServer LSPServer(*TransportLayer, TFS, Opts);
  LSPServer.run();
  return 0;
}
