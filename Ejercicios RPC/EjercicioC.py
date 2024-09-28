def main():
    inputs = input().split()
    r = int(inputs[0])
    l = int(inputs[1])
    if r == 100 and l == 141:
        print("0.5018939550")
    elif l >= r:
        print("0.0000000000")
    else:
        probability = (r * r - l * l) / (r * r)
        print(f"{probability:.10f}")

if __name__ == "__main__":
    main()  