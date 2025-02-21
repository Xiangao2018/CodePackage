<!-- <script setup lang="ts">
import HelloWorld from './components/HelloWorld.vue'
import TheWelcome from './components/TheWelcome.vue'
</script> -->

<script lang="ts" setup name = "App">

import HelloWorld from "@/components/HelloWorld.vue";
import TheWelcome from "@/components/TheWelcome.vue";

</script>

<template>
  <header>
      <HelloWorld msg="Hello Vue" />
  </header>

  <main>
    <TheWelcome />
  </main>
</template>

<style scoped>
</style>
