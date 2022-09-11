#include <stdio.h>
#define NAPI_EXPERIMENTAL
#define NAPI_EMBEDDING
#include <napi.h>

int main() {
    try {
        Napi::Platform platform;
        Napi::PlatformEnv env(platform);

        try {
            Napi::HandleScope scope(env);
            Napi::Function require =
                env.Global().Get("require").As<Napi::Function>();
            Napi::Object axios =
                require({Napi::String::New(env, "axios")}).ToObject();

            Napi::Value r =
                axios.Get("get")
                    .As<Napi::Function>()
                    .MakeCallback(
                        env.Global(),
                        {Napi::String::New(env, "https://www.google.com")})
                    .As<Napi::Promise>()
                    .Await();

            std::string data = r.ToObject().Get("data").ToString().Utf8Value();
            printf("Result is:\n\n%s\n", data.c_str());
        } catch (const Napi::Error &e) {
            fprintf(stderr, "Caught a JS exception: %s\n", e.what());
            return -1;
        }
    } catch (napi_status r) {
        fprintf(stderr, "Failed initializing Node.js environment: %d\n",
                (int)r);
        return -1;
    }

    return 0;
}
